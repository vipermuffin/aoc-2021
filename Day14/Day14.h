//
//  Advent of Code 2021 Solutions: Day 14
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/14/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>
#include <unordered_map>

namespace AocDay14 {
//Function Definitions
    std::unordered_map<std::string, std::string> buildReplacementList(const std::vector<std::string>&);
    std::string performSteps(std::unordered_map<std::string, std::string>&, std::string, int);
    int64_t countChars(const std::string&);
    std::unordered_map<std::string, std::string> buildReplacementList2(const std::vector<std::string>&);
    int64_t performSteps2(std::unordered_map<std::string, std::string>&, std::string, int);
    uint64_t performSteps3(std::unordered_map<std::string, std::string>&, std::string, int);
}
