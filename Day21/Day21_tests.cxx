//
//  Advent of Code 2021 Tests: Day 21
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/21/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//

#include "Day21.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay21{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay21;

TEST(Y2021_SolveDay21, FinalSolutionPartA) {
    EXPECT_EQ("920580", solvea());
}

TEST(Y2021_SolveDay21, FinalSolutionPartB) {
    EXPECT_EQ("647920021341197", solveb());
}

TEST(Y2021_Day21Example,Test1) {
    EXPECT_EQ(739785,playGame(4, 8));
}

TEST(Y2021_Day21Example,Test2) {
    EXPECT_EQ(444356092776315LL,playGame2(4,8));
}
