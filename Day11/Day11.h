//
//  Advent of Code 2021 Solutions: Day 11
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/10/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

namespace AocDay11 {
//Function Definitions
#if 0
class Octopus {
public:
    Octopus() = default;
    Octopus(uint8_t initEnergy);
    ~Octopus() = default;
    bool step();
};
#endif
std::vector<std::vector<uint8_t>> parseTextEnergy(const std::vector<std::string>&);
int32_t step(std::vector<std::vector<uint8_t>>&);
int32_t step(std::vector<std::vector<uint8_t>>&, int32_t);
int32_t findFirstAllFlashDay(const std::vector<std::string>& input);
}
