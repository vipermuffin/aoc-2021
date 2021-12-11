//
//  Advent of Code 2021 Solutions: Day 11
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/10/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//

#include "Day11.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <numeric> //std::accumulate
#include <unordered_set>

using namespace std;
namespace AocDay11 {

    static const std::string InputFileName = "Day11.txt";
    constexpr size_t COL = 0;
    constexpr size_t ROW = 1;
    typedef union {
        uint16_t xy;
        uint8_t val[2];
    } xyUnion_t;

    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        auto result = parseTextEnergy(input);
		return to_string(step(result,100));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
		return to_string(findFirstAllFlashDay(input));
    }

    int32_t step(std::vector<std::vector<uint8_t>>& matrix) {
        vector<std::pair<int,int>> fullList{};
        fullList.reserve(matrix.size()*matrix.size());
        xyUnion_t tmp{0};
        unordered_set<uint16_t> flashList{};
        //Step 1 add 1
        for(int row = 0; row < matrix.size(); row++) {
            for(int col = 0; col < matrix[row].size(); col++) {
                if(++matrix[row][col] > 9) {
                    fullList.emplace_back(row,col);
                    tmp.val[ROW] = row;
                    tmp.val[COL] = col;
                    flashList.insert(tmp.xy);
                }
            }
        }
        
        //Step 2 Flash
        bool done = false;
        while(!done) {
            vector<std::pair<int,int>> nextList{};
            nextList.reserve(matrix.size()*matrix.size());
            for(const auto& p : fullList) {
                for(int dy = -1;dy < 2; dy++) {
                    for(int dx = -1; dx < 2; dx++) {
                        int row = p.first+dy;
                        int col = p.second+dx;
                        if((dx==0 && dy == 0) ||
                           (row<0) || row >= matrix.size() ||
                           (col<0) || col >= matrix[row].size()) {
                            //self or OOB
                        } else {
                            tmp.val[ROW] = row;
                            tmp.val[COL] = col;
                            if((flashList.count(tmp.xy) == 0) && ++matrix[row][col] > 9) {
                                nextList.emplace_back(row,col);
                                flashList.insert(tmp.xy);
                            }
                        }
                    }
                }
            }
            done = nextList.size()==0;
            if(!done) {
                std::swap(fullList,nextList);
            }
        }
        
        //Step 3 Reset to 0
        for(int row = 0; row < matrix.size(); row++) {
            for(int col = 0; col < matrix[row].size(); col++) {
                if(matrix[row][col] > 9) {
                    matrix[row][col] = 0;
                }
            }
        }

        return flashList.size();
    }

    std::vector<std::vector<uint8_t>> parseTextEnergy(const std::vector<std::string>& input) {
        std::vector<std::vector<uint8_t>> output{};
        int i = 0;
        for(const auto& line : input) {
            vector<uint8_t> vals{};
            for(const auto& c : line) {
                vals.push_back(static_cast<uint8_t>(c - '0'));
            }
            output.push_back(vals);
        }
        return output;
    }

    int32_t step(std::vector<std::vector<uint8_t>>& input, int32_t steps) {
        vector<int32_t> flashCount{};
        for(int i = 0; i < steps; i++) {
            flashCount.push_back(step(input));
        }
        return std::accumulate(flashCount.begin(), flashCount.end(), 0);
    }

    int32_t findFirstAllFlashDay(const std::vector<std::string>& input) {
        auto result = parseTextEnergy(input);
        int i = 1;
        while(step(result) != 100) {
            i++;
        }
        return i;
    }
}
