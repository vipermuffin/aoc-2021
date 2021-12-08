//
//  Advent of Code 2021 Solutions: Day 7
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/06/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

namespace AocDay07 {
//Function Definitions
    int32_t findMinFuel(std::vector<int32_t>&);
    int32_t findMinFuel(std::vector<int32_t>&,bool);
    int32_t findMinFuel2(std::vector<int32_t>&);
    int32_t calcFuel(int32_t diff);
}
