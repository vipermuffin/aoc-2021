//
//  Advent of Code 2021 Main Runner: Day 22
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/22/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//
#include <stdio.h>
#include <string>
#include <iostream>

namespace AocDay22{
    extern std::string solvea();
    extern std::string solveb();
}
using namespace std;

int main(int argc, char *argv[]) {

    std::cout << "Day22" << "a: " << AocDay22::solvea() << std::endl;
    std::cout << "Day22" << "b: " << AocDay22::solveb() << std::endl;
    return 0;
}
