//
//  Advent of Code 2021 Tests: Day 3
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/02/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//

#include "Day03.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay03{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay03;

TEST(Y2021_SolveDay3, FinalSolutionPartA) {
    EXPECT_EQ("4174964", solvea());
}

TEST(Y2021_SolveDay3, FinalSolutionPartB) {
    EXPECT_EQ("4474944", solveb());
}

TEST(Y2021_Day3Example,Test1) {
    vector<string> x {
        "00100",
        "11110",
        "10110",
        "10111",
        "10101",
        "01111",
        "00111",
        "11100",
        "10000",
        "11001",
        "00010",
        "01010"
    };
    auto result = calculateGammaEpsilon(x);
    EXPECT_EQ(22,result.first);
    EXPECT_EQ(9,result.second);
}

TEST(Y2021_Day3Example,Test2) {
    vector<string> x {
        "00100",
        "11110",
        "10110",
        "10111",
        "10101",
        "01111",
        "00111",
        "11100",
        "10000",
        "11001",
        "00010",
        "01010"
    };
    auto result = findO2CO2(x);
    EXPECT_EQ(23,result.first);
    EXPECT_EQ(10,result.second);
}

