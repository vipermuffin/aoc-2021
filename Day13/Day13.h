//
//  Advent of Code 2021 Solutions: Day 13
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/12/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

namespace AocDay13 {
//Function Definitions
std::vector<std::vector<bool>> parseInputGrid(const std::vector<std::string>&);
std::vector<std::vector<bool>> performFold(const std::vector<std::vector<bool>>&, const std::string&);
int countDots(const std::vector<std::vector<bool>>&);

}
