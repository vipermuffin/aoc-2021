//
//  Advent of Code 2021 Main Runner: Day 5
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/04/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//
#include <stdio.h>
#include <string>
#include <iostream>

namespace AocDay05{
    extern std::string solvea();
    extern std::string solveb();
}
using namespace std;

int main(int argc, char *argv[]) {

    std::cout << "Day05" << "a: " << AocDay05::solvea() << std::endl;
    std::cout << "Day05" << "b: " << AocDay05::solveb() << std::endl;
    return 0;
}
