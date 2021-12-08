//
//  Advent of Code 2021 Solutions: Day 7
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/06/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//

#include "Day07.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <numeric> //std::accumulate

using namespace std;
namespace AocDay07 {

    template <class T>
    T average(const vector<T>& vals) {
        if(vals.size() == 0)
            return 0;
        return std::accumulate(vals.begin(), vals.end(), static_cast<T>(0))/vals.size();
    }
    
    static const std::string InputFileName = "Day07.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        auto positions = parseCsvLineForNum(input.front());
		return to_string(findMinFuel(positions,false));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        auto positions = parseCsvLineForNum(input.front());
        return to_string(findMinFuel(positions,true));
    }
    
    int32_t findMinFuel(std::vector<int32_t>& positions, bool useAdvFuel) {
        std::sort(positions.begin(),positions.end());
        int32_t minFuel = INT32_MAX;
        int32_t target = useAdvFuel ? average(positions) : positions[positions.size()/2];
        
        for(int i = target - 1 ; i <= target + 1;i++) {
            int sum{0};
            for(const auto& val : positions) {
                sum += useAdvFuel ? calcFuel(abs(val - i)) : abs(val - i);
            }
            if(sum < minFuel) {
                minFuel = sum;
            }
        }
        return minFuel;
    }
    
    int32_t calcFuel(int32_t diff) {
        int32_t sum{0};
        for(int i = 1; i<=diff;i++) {
            sum += i;
        }
        return sum;
    }
}
