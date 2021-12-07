//
//  Advent of Code 2021 Tests: Day 6
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/05/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//

#include "Day06.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay06{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay06;

TEST(Y2021_SolveDay6, FinalSolutionPartA) {
    EXPECT_EQ("349549", solvea());
}

TEST(Y2021_SolveDay6, FinalSolutionPartB) {
    EXPECT_EQ("1589590444365", solveb());
}

TEST(Y2021_Day6Example,Test0) {
    vector<int32_t> x{3,4,3,1,2};
    EXPECT_EQ(5,performSimulationForXDays(x, 1));
    EXPECT_EQ(6,performSimulationForXDays(x, 2));
    EXPECT_EQ(7,performSimulationForXDays(x, 3));
    EXPECT_EQ(9,performSimulationForXDays(x, 4));
    EXPECT_EQ(10,performSimulationForXDays(x, 5));
    EXPECT_EQ(10,performSimulationForXDays(x, 6));
    EXPECT_EQ(10,performSimulationForXDays(x, 7));
    EXPECT_EQ(10,performSimulationForXDays(x, 8));
    EXPECT_EQ(11,performSimulationForXDays(x, 9));
    EXPECT_EQ(12,performSimulationForXDays(x, 10));
    EXPECT_EQ(15,performSimulationForXDays(x, 11));
    EXPECT_EQ(17,performSimulationForXDays(x, 12));
    EXPECT_EQ(19,performSimulationForXDays(x, 13));
    EXPECT_EQ(20,performSimulationForXDays(x, 14));
    EXPECT_EQ(20,performSimulationForXDays(x, 15));
    EXPECT_EQ(21,performSimulationForXDays(x, 16));
    EXPECT_EQ(22,performSimulationForXDays(x, 17));
    EXPECT_EQ(26,performSimulationForXDays(x, 18));
}

TEST(Y2021_Day6Example,Test1) {
    vector<int32_t> x{3,4,3,1,2};
    EXPECT_EQ(26,performSimulationForXDays(x, 18));
}

TEST(Y2021_Day6Example,Test2) {
    vector<int32_t> x{3,4,3,1,2};
    EXPECT_EQ(5934,performSimulationForXDays(x, 80));
}

TEST(Y2021_Day6Example,Test3) {
    vector<int32_t> x{3,4,3,1,2};
    EXPECT_EQ(26984457539,performSimulationForXDays(x, 256));
}
