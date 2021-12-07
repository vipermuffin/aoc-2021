//
//  Advent of Code 2021 Main Runner: Day 6
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/05/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//
#include <stdio.h>
#include <string>
#include <iostream>

namespace AocDay06{
    extern std::string solvea();
    extern std::string solveb();
}
using namespace std;

int main(int argc, char *argv[]) {

    std::cout << "Day06" << "a: " << AocDay06::solvea() << std::endl;
    std::cout << "Day06" << "b: " << AocDay06::solveb() << std::endl;
    return 0;
}
