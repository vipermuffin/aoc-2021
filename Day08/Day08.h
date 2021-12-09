//
//  Advent of Code 2021 Solutions: Day 8
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/07/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>
#include <unordered_map>

namespace AocDay08 {
//Function Definitions
    int32_t countEasyDigits(const std::vector<std::string>&);
    std::unordered_map<std::string, std::string> decodeDigits(const std::string&);
    int32_t getOutputVal(const std::string&);
    int32_t SumOutputVals(const std::vector<std::string>&);
}
