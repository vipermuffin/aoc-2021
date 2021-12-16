//
//  Advent of Code 2021 Main Runner: Day 14
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/14/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//
#include <stdio.h>
#include <string>
#include <iostream>

namespace AocDay14{
    extern std::string solvea();
    extern std::string solveb();
}
using namespace std;

int main(int argc, char *argv[]) {

    std::cout << "Day14" << "a: " << AocDay14::solvea() << std::endl;
    std::cout << "Day14" << "b: " << AocDay14::solveb() << std::endl;
    return 0;
}
