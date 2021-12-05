//
//  Advent of Code 2021 Solutions: Day 5
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/04/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//

#include "Day05.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <cstdio>
#include <numeric> //std::accumulate


using namespace std;
namespace AocDay05 {

    static const std::string InputFileName = "Day05.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
		return to_string(countOverlap(input));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        return to_string(countOverlap(input,true));
    }

    void parseLine(const std::string& line, std::unordered_map<uint64_t,int32_t>& dataBase, bool useDiagnal) {
        int32_t x1,x2,y1,y2;
        sscanf(line.c_str(), "%d,%d -> %d,%d", &x1,&y1,&x2,&y2);
        xyUnion_t tmp;
        tmp.xy = 0;
        if(x1 == x2) {
            //Vertical line.  Need to add each y point in range
            tmp.val[X] = x1;
            int32_t yBegin = y1 > y2 ? y2 : y1;
            int32_t yEnd = y1 < y2 ? y2 : y1;
            for(int32_t y = yBegin; y <= yEnd; y++) {
                tmp.val[Y] = y;
                dataBase[tmp.xy]++;
            }
        } else if(y1 == y2){
            //Horizontal line.  Need to add each x point in range
            tmp.val[Y] = y1;
            int32_t xBegin = x1 > x2 ? x2 : x1;
            int32_t xEnd = x1 < x2 ? x2 : x1;
            for(int32_t x = xBegin; x <= xEnd; x++) {
                tmp.val[X] = x;
                dataBase[tmp.xy]++;
            }
        } else if(useDiagnal) {
            int32_t yBegin = y1 > y2 ? y2 : y1;
            int32_t yEnd = y1 < y2 ? y2 : y1;
            //This is a diagnal line.  Requirements state on 45 degree, which allows slope of 1
            //Just need to determine the direction
            int32_t xSlope = y1 > y2 ? (x1 > x2 ? 1 : -1) : (x1 > x2 ? -1 : 1);
            int32_t x = y1 > y2 ? x2 : x1;
            for(int32_t y = yBegin; y <= yEnd; y++) {
                tmp.val[Y] = y;
                tmp.val[X] = x;
                dataBase[tmp.xy]++;
                x += xSlope;
            }
        }
    }

    int32_t countOverlap(const std::vector<std::string>& input, bool useDiagnal) {
        unordered_map<uint64_t, int32_t> db{};
        //Populate the map with the datapoints
        for(const auto& line : input) {
            parseLine(line, db, useDiagnal);
        }
        //auto count = std::count_if(db.begin(),db.end(),0,[](uint64_t,int32_t x){return x>1;});
        int32_t count{0};
        for(const auto& kvp : db) {
            if(kvp.second > 1)
                count++;
        }
        
        return count;
    }

}
