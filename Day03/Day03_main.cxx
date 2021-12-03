//
//  Advent of Code 2021 Main Runner: Day 3
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/02/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//
#include <stdio.h>
#include <string>
#include <iostream>

namespace AocDay03{
    extern std::string solvea();
    extern std::string solveb();
}
using namespace std;

int main(int argc, char *argv[]) {

    std::cout << "Day03" << "a: " << AocDay03::solvea() << std::endl;
    std::cout << "Day03" << "b: " << AocDay03::solveb() << std::endl;
    return 0;
}
