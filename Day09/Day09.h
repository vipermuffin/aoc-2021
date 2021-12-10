//
//  Advent of Code 2021 Solutions: Day 9
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/08/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>
#include <unordered_set>

namespace AocDay09 {
//Function Definitions
    int32_t calcLowPointRisk(const std::vector<std::string>&, std::vector<uint64_t>* lowPointCoords = nullptr);
    int32_t countBasinSize(const std::vector<std::string>& lines, std::unordered_set<uint64_t>&,int32_t row, int32_t col);
    int32_t calcBasinVal(const std::vector<std::string>& lines);

}
