//
//  Advent of Code 2021 Solutions: Day 22
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/22/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>
#include <unordered_map>

namespace AocDay22 {
//Function Definitions
typedef struct {
    int64_t x:21;
    int64_t y:21;
    int64_t z:21;
    int64_t rsvd:1;
}PointInfo_S;
typedef union {
    uint64_t all;
    PointInfo_S p;
} PointInfo_t;

void updatePointGrid(std::unordered_map<uint64_t, bool>& pointGrid, const std::string& ins, const bool init);
std::unordered_map<uint64_t, bool> generatePointGrid(const std::vector<std::string>&, const bool init = true);
int64_t countOnPoints(std::unordered_map<uint64_t, bool>& pointGrid);
}
