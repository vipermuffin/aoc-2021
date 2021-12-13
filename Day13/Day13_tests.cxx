//
//  Advent of Code 2021 Tests: Day 13
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/12/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//

#include "Day13.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay13{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay13;

TEST(Y2021_SolveDay13, FinalSolutionPartA) {
    EXPECT_EQ("664", solvea());
}

TEST(Y2021_SolveDay13, FinalSolutionPartB) {
    EXPECT_EQ("---", solveb());
}

TEST(Y2021_Day13Example,Test1) {
    vector<string> x{
        "6,10",
        "0,14",
        "9,10",
        "0,3",
        "10,4",
        "4,11",
        "6,0",
        "6,12",
        "4,1",
        "0,13",
        "10,12",
        "3,4",
        "3,0",
        "8,4",
        "1,10",
        "2,14",
        "8,10",
        "9,0",
        "",
        "fold along y=7",
        "fold along x=5"
    };
    auto grid = parseInputGrid(x);
    EXPECT_EQ(15,grid.size());
    EXPECT_EQ(11,grid.front().size());
    EXPECT_FALSE(grid[0][0]);
    EXPECT_TRUE(grid[14][0]);
}

TEST(Y2021_Day13Example,Test2) {
    vector<string> x{
        "6,10",
        "0,14",
        "9,10",
        "0,3",
        "10,4",
        "4,11",
        "6,0",
        "6,12",
        "4,1",
        "0,13",
        "10,12",
        "3,4",
        "3,0",
        "8,4",
        "1,10",
        "2,14",
        "8,10",
        "9,0",
        "",
        "fold along y=7",
        "fold along x=5"
    };
    auto grid = parseInputGrid(x);
    string instruction{"fold along y=7"};
    auto newGrid = performFold(grid, instruction);
    
    EXPECT_EQ(7,newGrid.size());
    EXPECT_EQ(11,newGrid.front().size());
    
    instruction = "fold along x=5";
    auto fold2Grid = performFold(newGrid, instruction);
    EXPECT_EQ(7,fold2Grid.size());
    EXPECT_EQ(5,fold2Grid.front().size());
}
