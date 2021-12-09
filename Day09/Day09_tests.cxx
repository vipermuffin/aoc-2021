//
//  Advent of Code 2021 Tests: Day 9
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/08/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//

#include "Day09.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay09{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay09;

TEST(Y2021_SolveDay9, FinalSolutionPartA) {
    EXPECT_EQ("558", solvea());
}

TEST(Y2021_SolveDay9, FinalSolutionPartB) {
    EXPECT_EQ("882942", solveb());
}

TEST(Y2021_Day9Example,Test1) {
    vector<string> x{
        "2199943210",
        "3987894921",
        "9856789892",
        "8767896789",
        "9899965678"
    };
    EXPECT_EQ(15,calcLowPointRisk(x));
}

TEST(Y2021_Day9Example,Test2a) {
    vector<string> x{
        "2199943210",
        "3987894921",
        "9856789892",
        "8767896789",
        "9899965678"
    };
    unordered_set<uint64_t> v{};
    EXPECT_EQ(3,countBasinSize(x, v, 0, 1));
}
TEST(Y2021_Day9Example,Test2b) {
    vector<string> x{
        "2199943210",
        "3987894921",
        "9856789892",
        "8767896789",
        "9899965678"
    };
    unordered_set<uint64_t> v{};
    EXPECT_EQ(9,countBasinSize(x, v, 0, 9));
}
TEST(Y2021_Day9Example,Test2c) {
    vector<string> x{
        "2199943210",
        "3987894921",
        "9856789892",
        "8767896789",
        "9899965678"
    };
    unordered_set<uint64_t> v{};
    EXPECT_EQ(14,countBasinSize(x, v, 2, 2));
}
TEST(Y2021_Day9Example,Test2d) {
    vector<string> x{
        "2199943210",
        "3987894921",
        "9856789892",
        "8767896789",
        "9899965678"
    };
    unordered_set<uint64_t> v{};
    EXPECT_EQ(9,countBasinSize(x, v, 4, 6));
}

TEST(Y2021_Day9Example,Test3) {
    vector<string> x{
        "2199943210",
        "3987894921",
        "9856789892",
        "8767896789",
        "9899965678"
    };
    
    EXPECT_EQ(1134,calcBasinVal(x));
}
