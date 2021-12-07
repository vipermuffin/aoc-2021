//
//  Advent of Code 2021 Solutions: Day 6
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/05/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//

#include "Day06.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <numeric> //std::accumulate


using namespace std;
namespace AocDay06 {

    static const std::string InputFileName = "Day06.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        auto vals = parseCsvLineForNum(input.front());
		return to_string(performSimulationForXDays(vals, 80));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        auto vals = parseCsvLineForNum(input.front());
		return to_string(performSimulationForXDays(vals, 256));
    }
    
    int64_t performSimulationForXDays(const std::vector<int32_t>& initDayList,int32_t days) {
        vector<int64_t> mature{}, newFish{};
        mature.resize(7,0);
        newFish.resize(9,0);
        for(const auto& x : initDayList) {
            mature[x]++;
        }
        int idx = 0;
        int newIdx = 0;
        for(int i = 0; i < days; i++) {
            mature[idx] += newFish[newIdx];
            newFish[newIdx] = mature[idx];
            //Increment and reset overflow
            if(++newIdx > 8)
                newIdx = 0;
            if(++idx > 6)
                idx = 0;
        }

        int64_t count = std::accumulate(mature.begin(), mature.end(), std::accumulate(newFish.begin(), newFish.end(), 0ULL));
        return count;
    }

}
