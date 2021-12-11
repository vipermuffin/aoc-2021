//
//  Advent of Code 2021 Tests: Day 11
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/10/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//

#include "Day11.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay11{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay11;

TEST(Y2021_SolveDay11, FinalSolutionPartA) {
    EXPECT_EQ("1683", solvea());
}

TEST(Y2021_SolveDay11, FinalSolutionPartB) {
    EXPECT_EQ("788", solveb());
}

TEST(Y2021_Day11Example,Test1a) {
    vector<vector<uint8_t>> x{
        {1,1,1,1,1},
        {1,9,9,9,1},
        {1,9,1,9,1},
        {1,9,9,9,1},
        {1,1,1,1,1}
    };
    vector<vector<uint8_t>> expected {
        {3,4,5,4,3},
        {4,0,0,0,4},
        {5,0,0,0,5},
        {4,0,0,0,4},
        {3,4,5,4,3}
    };
    EXPECT_EQ(9,step(x));
    for(int i = 0; i < x.size(); i++) {
        for(int j = 0; j < x[i].size();j++) {
            EXPECT_EQ(expected[i][j], x[i][j]);
        }
    }
}

TEST(Y2021_Day11Example,Test1b) {
    vector<vector<uint8_t>> x{
        {3,4,5,4,3},
        {4,0,0,0,4},
        {5,0,0,0,5},
        {4,0,0,0,4},
        {3,4,5,4,3}
    };
    vector<vector<uint8_t>> expected {
        {4,5,6,5,4},
        {5,1,1,1,5},
        {6,1,1,1,6},
        {5,1,1,1,5},
        {4,5,6,5,4}
    };
    EXPECT_EQ(0,step(x));

    for(int i = 0; i < x.size(); i++) {
        for(int j = 0; j < x[i].size();j++) {
            EXPECT_EQ(expected[i][j], x[i][j]);
        }
    }
}

TEST(Y2021_Day11Example,Test2) {
    vector<string> x{
        "0123",
        "4567",
        "8901"
    };
    vector<vector<uint8_t>> expected {
        {0,1,2,3},
        {4,5,6,7},
        {8,9,0,1},
        {0,1,2,3},
        {4,5,6,7}
    };
    auto result = parseTextEnergy(x);
    for(int i = 0; i < x.size(); i++) {
        for(int j = 0; j < x[i].size();j++) {
            EXPECT_EQ(expected[i][j], result[i][j]);
        }
    }
}

TEST(Y2021_Day11Example,Test3) {
    vector<string> x{
        "5483143223",
        "2745854711",
        "5264556173",
        "6141336146",
        "6357385478",
        "4167524645",
        "2176841721",
        "6882881134",
        "4846848554",
        "5283751526"
    };
    auto result = parseTextEnergy(x);
    EXPECT_EQ(1656,step(result,100));
}

TEST(Y2021_Day11Example,Test4) {
    vector<string> x{
        "5483143223",
        "2745854711",
        "5264556173",
        "6141336146",
        "6357385478",
        "4167524645",
        "2176841721",
        "6882881134",
        "4846848554",
        "5283751526"
    };
    EXPECT_EQ(195,findFirstAllFlashDay(x));
}
