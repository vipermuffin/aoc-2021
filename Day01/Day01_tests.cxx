//
//  Advent of Code 2021 Tests: Day 1
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 11/30/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//

#include "Day01.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay01{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay01;

TEST(Y2021_SolveDay1, FinalSolutionPartA) {
    EXPECT_EQ("1532", solvea());
}

TEST(Y2021_SolveDay1, FinalSolutionPartB) {
    EXPECT_EQ("1571", solveb());
}

TEST(Y2021_Day1Example,Example1a) {
    vector<int> x{
        199,
        200,
        208,
        210,
        200,
        207,
        240,
        269,
        260,
        263};
    
    EXPECT_EQ(7,countIncreasing(x));
}

TEST(Y2021_Day1Example,Example1b) {
    vector<int> input{
        199,
        200,
        208,
        210,
        200,
        207,
        240,
        269,
        260,
        263};
    std::vector<int> x{};
    x.reserve(input.size());
    for(int i = 0; i<input.size()-2;i++) {
        x.push_back(input[i]+input[i+1]+input[i+2]);
    }
    EXPECT_EQ(5,countIncreasing(x));
}

