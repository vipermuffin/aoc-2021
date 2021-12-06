//
//  Advent of Code 2021 Tests: Day 5
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/04/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//

#include "Day05.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay05{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay05;

TEST(Y2021_SolveDay5, FinalSolutionPartA) {
    EXPECT_EQ("6461", solvea());
}

TEST(Y2021_SolveDay5, FinalSolutionPartB) {
    EXPECT_EQ("18065", solveb());
}

TEST(Y2021_Day5Example,VerifyParseOfCoordinates) {
    string x{"0,9 -> 5,9"};
    unordered_map<uint64_t, int32_t> db{};
    parseLine(x, db);
    EXPECT_EQ(6,db.size());
}

TEST(Y2021_Day5Example,TestCountOverlap) {
    vector<string> x {
        "0,9 -> 5,9",
        "8,0 -> 0,8",
        "9,4 -> 3,4",
        "2,2 -> 2,1",
        "7,0 -> 7,4",
        "6,4 -> 2,0",
        "0,9 -> 2,9",
        "3,4 -> 1,4",
        "0,0 -> 8,8",
        "5,5 -> 8,2"
    };
    EXPECT_EQ(5,countOverlap(x));
}

TEST(Y2021_Day5Example,TestCountOverlapWithDiagnals) {
    vector<string> x {
        "0,9 -> 5,9",
        "8,0 -> 0,8",
        "9,4 -> 3,4",
        "2,2 -> 2,1",
        "7,0 -> 7,4",
        "6,4 -> 2,0",
        "0,9 -> 2,9",
        "3,4 -> 1,4",
        "0,0 -> 8,8",
        "5,5 -> 8,2"
    };
    EXPECT_EQ(12,countOverlap(x,true));
}
