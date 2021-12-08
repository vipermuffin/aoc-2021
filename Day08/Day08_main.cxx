//
//  Advent of Code 2021 Main Runner: Day 8
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/07/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//
#include <stdio.h>
#include <string>
#include <iostream>

namespace AocDay08{
    extern std::string solvea();
    extern std::string solveb();
}
using namespace std;

int main(int argc, char *argv[]) {

    std::cout << "Day08" << "a: " << AocDay08::solvea() << std::endl;
    std::cout << "Day08" << "b: " << AocDay08::solveb() << std::endl;
    return 0;
}
