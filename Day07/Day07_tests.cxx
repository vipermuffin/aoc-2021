//
//  Advent of Code 2021 Tests: Day 7
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/06/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//

#include "Day07.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay07{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay07;

TEST(Y2021_SolveDay7, FinalSolutionPartA) {
    EXPECT_EQ("336721", solvea());
}

TEST(Y2021_SolveDay7, FinalSolutionPartB) {
    EXPECT_EQ("91638945", solveb());
}

TEST(Y2021_Day7Example,Test1) {
    vector<int32_t>x {16,1,2,0,4,2,7,1,2,14};
    EXPECT_EQ(37,findMinFuel(x));
}

TEST(Y2021_Day7Example,Test2) {
    vector<int32_t>x {16,1,2,0,4,2,7,1,2,14};
    EXPECT_EQ(168,findMinFuel2(x));
}

TEST(Y2021_Day7Example,Test3) {
    EXPECT_EQ(66, calcFuel(abs(16-5)));
    EXPECT_EQ(10, calcFuel(abs(1-5)));
    EXPECT_EQ(6, calcFuel(abs(2-5)));
    EXPECT_EQ(15, calcFuel(abs(0-5)));
    EXPECT_EQ(1, calcFuel(abs(4-5)));
    EXPECT_EQ(3, calcFuel(abs(7-5)));
    EXPECT_EQ(6, calcFuel(abs(2-5)));
    EXPECT_EQ(45, calcFuel(abs(14-5)));
    EXPECT_EQ(0, calcFuel(abs(5-5)));
}
