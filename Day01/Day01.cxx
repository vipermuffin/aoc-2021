//
//  Advent of Code 2021 Solutions: Day 1
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 11/30/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//

#include "Day01.h"
#include "AoCUtils.h"
//Common Libraries

using namespace std;
namespace AocDay01 {

    static const std::string InputFileName = "Day01.txt";

    int countIncreasing(const std::vector<int>& input) {
        int count{0};
        for(int i = 1; i<input.size();i++) {
            if ( input[i] > input[i-1]) {
                count++;
            }
        }
        return count;
    }

    std::string solvea() {
        auto input = parseFileForNumberPerLine(InputFileName);
        
		return to_string(countIncreasing(input));
    }

    std::string solveb() {
        auto input = parseFileForNumberPerLine(InputFileName);
        std::vector<int> x{};
        x.reserve(input.size());
        for(int i = 0; i<input.size()-2;i++) {
            x.push_back(input[i]+input[i+1]+input[i+2]);
        }
		return to_string(countIncreasing(x));
    }

}
