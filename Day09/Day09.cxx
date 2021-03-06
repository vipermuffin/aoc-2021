//
//  Advent of Code 2021 Solutions: Day 9
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/08/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//

#include "Day09.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <numeric> //std::accumulate


using namespace std;
namespace AocDay09 {

    static const std::string InputFileName = "Day09.txt";
    constexpr size_t COL = 0;
    constexpr size_t ROW = 1;
    typedef union {
        uint64_t xy;
        int32_t val[2];
    } xyUnion_t;
    
    std::string solvea() {
        //553 too low
        auto input = parseFileForLines(InputFileName);

		return to_string(calcLowPointRisk(input));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);

		return to_string(calcBasinVal(input));
    }

    int32_t calcLowPointRisk(const std::vector<std::string>& lines, std::vector<uint64_t>* lowPointCoords) {
        vector<int32_t> lowPoints{};
        xyUnion_t tmp{0};
        
        //Find all low points
        for(int row=0;row < lines.size();row++) {
            for(int col=0; col < lines[row].size(); col++) {
                int count{0};
                for(int dx = -1; dx <= 1; dx++) {
                    int x = col + dx;
                    if((x < 0) || (x >= lines[row].size())) {
                        count++;
                    }else {
                        if(lines[row][col] < lines[row][x]) {
                            count++;
                        }
                    }
                }
                for(int dy= -1; dy<= 1; dy++) {
                    int y = row + dy;
                    if((y < 0) || (y >= lines.size())) {
                        count++;
                    }else {
                        if(lines[row][col] < lines[y][col]) {
                            count++;
                        }
                    }
                }
                if(count == 4) {
                    auto val = lines[row][col];
                    lowPoints.push_back(static_cast<int32_t>(val-'0')+1);
                    if(lowPointCoords != nullptr) {
                        tmp.val[COL] = col;
                        tmp.val[ROW] = row;
                        lowPointCoords->push_back(tmp.xy);
                    }
                }
            }
        }
        return std::accumulate(lowPoints.begin(), lowPoints.end(), static_cast<int32_t>(0));
    }
    
    int32_t calcBasinVal(const std::vector<std::string>& lines) {
        vector<uint64_t> lowPoints{};
        xyUnion_t tmp{0};
        calcLowPointRisk(lines,&lowPoints);

        vector<int32_t> basinVals{};
        for(const auto p : lowPoints) {
            unordered_set<uint64_t> visited{};
            tmp.xy = p;
            basinVals.push_back(countBasinSize(lines, visited, tmp.val[ROW], tmp.val[COL]));
        }
        std::sort(basinVals.begin(),basinVals.end());
        auto rItr = basinVals.rbegin();
        int32_t product{1};
        for(int i = 0; i < 3; i++) {
            product *= *rItr;
            rItr++;
        }
        return product;
    }
    
    int32_t countBasinSize(const std::vector<std::string>& lines, std::unordered_set<uint64_t>& visited, int32_t row, int32_t col) {
        xyUnion_t tmp{0};
        tmp.val[COL] = col;
        tmp.val[ROW] = row;
        visited.insert(tmp.xy);
        if(lines[row][col] == '9') {
            return 0;
        }
        
        int count{0};
        for(int dx = -1; dx <= 1; dx+=2) {
            int x = col + dx;
            tmp.val[COL] = x;
            tmp.val[ROW] = row;
            if((x < 0) || (x >= lines[row].size()) || visited.count(tmp.xy) > 0) {
                
            }else {
                count += countBasinSize(lines, visited, row, x);
            }
        }
        for(int dy= -1; dy<= 1; dy+=2) {
            int y = row + dy;
            tmp.val[COL] = col;
            tmp.val[ROW] = y;
            if((y < 0) || (y >= lines.size()) || visited.count(tmp.xy) > 0) {
                
            }else {
                count += countBasinSize(lines, visited, y, col);
            }
        }
        return 1+count;
    }
}
