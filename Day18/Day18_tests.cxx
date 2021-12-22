//
//  Advent of Code 2021 Tests: Day 18
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/18/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//

#include "Day18.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay18{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay18;

TEST(Y2021_SolveDay18, FinalSolutionPartA) {
    EXPECT_EQ("---", solvea());
}

TEST(Y2021_SolveDay18, FinalSolutionPartB) {
    EXPECT_EQ("---", solveb());
}

TEST(Y2021_Day18Example,Test1) {
    SnailfishNumber x{1,2};
    auto sn = x.toString();
    EXPECT_EQ("[1,2]",sn);
}

TEST(Y2021_Day18Example,Test2) {
    SnailfishNumber x1{1,2};
    SnailfishNumber x2{3,4};
    x1 += x2;
    auto sn = x1.toString();
    EXPECT_EQ("[[1,2],[3,4]]",sn);
}

TEST(Y2021_Day18Example,Test3) {
    SnailfishNumber x0{"[2,1]"};
    SnailfishNumber x1{"[[1,2],3]"};
    SnailfishNumber x2{"[9,[8,7]]"};
    SnailfishNumber x3{"[[1,9],[8,5]]"};
    SnailfishNumber x4{"[[[[1,2],[3,4]],[[5,6],[7,8]]],9]"};
    SnailfishNumber x5{"[[[9,[3,8]],[[0,9],6]],[[[3,7],[4,9]],3]]"};
    SnailfishNumber x6{"[[[[1,3],[5,3]],[[1,3],[8,7]]],[[[4,9],[6,9]],[[8,2],[7,3]]]]"};
    
    EXPECT_EQ("[2,1]",x0.toString());
    EXPECT_EQ("[[1,2],3]",x1.toString());
    EXPECT_EQ("[9,[8,7]]",x2.toString());
    EXPECT_EQ("[[1,9],[8,5]]",x3.toString());
    EXPECT_EQ("[[[[1,2],[3,4]],[[5,6],[7,8]]],9]",x4.toString());
    EXPECT_EQ("[[[9,[3,8]],[[0,9],6]],[[[3,7],[4,9]],3]]",x5.toString());
    EXPECT_EQ("[[[[1,3],[5,3]],[[1,3],[8,7]]],[[[4,9],[6,9]],[[8,2],[7,3]]]]", x6.toString());
}

TEST(Y2021_Day18Example,Test4) {
    SnailfishNumber x0{"[1,2]"};
    SnailfishNumber x1{"[[3,4],5]"};
    
    x0 += x1;
    
    EXPECT_EQ("[[1,2],[[3,4],5]]",x0.toString());
}

TEST(Y2021_Day18Example,Test5) {
    SnailfishNumber x0{"[[1,2],[[3,4],5]]"};
    SnailfishNumber x1{"[[[[0,7],4],[[7,8],[6,0]]],[8,1]]"};
    SnailfishNumber x2{"[[[[1,1],[2,2]],[3,3]],[4,4]]"};
    SnailfishNumber x3{"[[[[3,0],[5,3]],[4,4]],[5,5]]"};
    SnailfishNumber x4{"[[[[5,0],[7,4]],[5,5]],[6,6]]"};
    SnailfishNumber x5{"[[[[8,7],[7,7]],[[8,6],[7,7]]],[[[0,7],[6,6]],[8,7]]]"};
    
    EXPECT_EQ(143,x0.magnitude());
    EXPECT_EQ(1384, x1.magnitude());
    EXPECT_EQ(445, x2.magnitude());
    EXPECT_EQ(791, x3.magnitude());
    EXPECT_EQ(1137, x4.magnitude());
    EXPECT_EQ(3488, x5.magnitude());
}

TEST(Y2021_Day18Example,Test6) {
    SnailfishNumber x0{"[[[[[9,8],1],2],3],4]"};
    SnailfishNumber x1{"[7,[6,[5,[4,[3,2]]]]]"};
    SnailfishNumber x2{"[[6,[5,[4,[3,2]]]],1]"};
    SnailfishNumber x3{"[[3,[2,[1,[7,3]]]],[6,[5,[4,[3,2]]]]]"};
//    SnailfishNumber x4{""};
//    SnailfishNumber x5{""};
    x0.reduce();
    x1.reduce();
    x2.reduce();
    x3.reduce();
    EXPECT_EQ("[[[[0,9],2],3],4]",x0.toString());
    EXPECT_EQ("[7,[6,[5,[7,0]]]]", x1.toString());
    EXPECT_EQ("[[6,[5,[7,0]]],3]", x2.toString());
    EXPECT_EQ("[[3,[2,[8,0]]],[9,[5,[7,0]]]]", x3.toString());
//    EXPECT_EQ(1137, x4.magnitude());
//    EXPECT_EQ(3488, x5.magnitude());
}
