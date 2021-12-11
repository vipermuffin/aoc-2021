//
//  Advent of Code 2021 Main Runner: Day 10
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/09/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//
#include <stdio.h>
#include <string>
#include <iostream>

namespace AocDay10{
    extern std::string solvea();
    extern std::string solveb();
}
using namespace std;

int main(int argc, char *argv[]) {

    std::cout << "Day10" << "a: " << AocDay10::solvea() << std::endl;
    std::cout << "Day10" << "b: " << AocDay10::solveb() << std::endl;
    return 0;
}
