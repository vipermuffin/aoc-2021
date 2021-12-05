//
//  Advent of Code 2021 Solutions: Day 5
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/04/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>
#include <unordered_map>

namespace AocDay05 {
//Function Definitions
constexpr size_t X = 0;
constexpr size_t Y = 1;
typedef union {
    uint64_t xy;
    int32_t val[2];
} xyUnion_t;

void parseLine(const std::string&, std::unordered_map<uint64_t,int32_t>&, bool useDiagnal = false);
int32_t countOverlap(const std::vector<std::string>&, bool useDiagnal = false);
}
