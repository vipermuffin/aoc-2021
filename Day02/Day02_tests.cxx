//
//  Advent of Code 2021 Tests: Day 2
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/01/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//

#include "Day02.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay02{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay02;

TEST(Y2021_SolveDay2, FinalSolutionPartA) {
    EXPECT_EQ("1580000", solvea());
}

TEST(Y2021_SolveDay2, FinalSolutionPartB) {
    EXPECT_EQ("1251263225", solveb());
}

TEST(Y2021_Day2Example,Test1) {
    vector<string> x{
        "forward 5",
        "down 5",
        "forward 8",
        "up 3",
        "down 8",
        "forward 2"
    };
    auto result = followPath(x);
    EXPECT_EQ(15,result.first);
    EXPECT_EQ(10, result.second);
}

TEST(Y2021_Day2Example,Test2) {
    vector<string> x{
        "forward 5",
        "down 5",
        "forward 8",
        "up 3",
        "down 8",
        "forward 2"
    };
    auto result = followPath(x,true);
    EXPECT_EQ(15,result.first);
    EXPECT_EQ(60, result.second);
}
