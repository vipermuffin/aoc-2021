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
//#include <array>
#include <climits>   //INT_MIN, INT_MAX, etc.
//#include <chrono>
//#include <iostream>
//#include <fstream> //ifstream
//#include <functional> //std::function
//#include <iomanip> //setfill setw hex
//#include <map>
//#include <math.h> //sqrt
//#include <numeric> //std::accumulate
//#include <queue>
//#include <regex>
//#include <set>
//#include <sstream>
//#include <thread>
//#include <tuple>
//#include <unordered_map>
//#include <unordered_set>


using namespace std;
namespace AocDay07 {

    static const std::string InputFileName = "Day07.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        auto positions = parseCsvLineForNum(input.front());
		return to_string(findMinFuel(positions));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        auto positions = parseCsvLineForNum(input.front());
        return to_string(findMinFuel2(positions));
    }
    
    int32_t findMinFuel(std::vector<int32_t>& positions) {
        std::sort(positions.begin(),positions.end());
        int32_t minFuel = INT32_MAX;
        auto median = positions.size()/2;
        
        for(int i = median - 1 ; i <= median + 1;i++) {
            int x = positions[i];
            int sum{0};
            for(const auto& val : positions) {
                sum += abs(val - x);
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
    int32_t findMinFuel2(std::vector<int32_t>& positions) {
        std::sort(positions.begin(),positions.end());
        int32_t minFuel = INT32_MAX;
        
        for(int i = 0 ; i <= positions.back();i++) {
            int x = i;
            int sum{0};
            for(const auto& val : positions) {
                sum += calcFuel(abs(val - x));
            }
            if(sum < minFuel) {
                minFuel = sum;
            }
        }
        return minFuel;
    }

}
