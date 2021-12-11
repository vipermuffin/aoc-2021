//
//  Advent of Code 2021 Solutions: Day 10
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/09/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

namespace AocDay10 {
//Function Definitions
char findFirstIllegalChar(const std::string&);
int64_t calcSyntaxScore(const std::vector<std::string>&);
int64_t calcIncompleteScore(const std::string&);
}
