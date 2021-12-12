//
//  Advent of Code 2021 Solutions: Day 12
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/11/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>
#include <unordered_map>

namespace AocDay12 {
//Function Definitions
std::unordered_map<std::string,std::vector<std::string>> parseInput(const std::vector<std::string>&);
std::vector<std::string> findPossiblePaths(const std::unordered_map<std::string,std::vector<std::string>>& connections);
std::vector<std::string> findPossiblePaths2(const std::unordered_map<std::string,std::vector<std::string>>& connections);
}
