//
//  Advent of Code 2021 Tests: Day 10
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/09/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//

#include "Day10.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay10{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay10;

TEST(Y2021_SolveDay10, FinalSolutionPartA) {
    EXPECT_EQ("367059", solvea());
}

TEST(Y2021_SolveDay10, FinalSolutionPartB) {
    EXPECT_EQ("1952146692", solveb());
}

TEST(Y2021_Day10Example,Test1a) {
    string x{"{([(<{}[<>[]}>{[]{[(<()>"};
    EXPECT_EQ('}',findFirstIllegalChar(x));
}

TEST(Y2021_Day10Example,Test1b) {
    string x{"[[<[([]))<([[{}[[()]]]"};
    EXPECT_EQ(')',findFirstIllegalChar(x));
}

TEST(Y2021_Day10Example,Test1c) {
    string x{"[{[{({}]{}}([{[{{{}}([]"};
    EXPECT_EQ(']',findFirstIllegalChar(x));
}

TEST(Y2021_Day10Example,Test1d) {
    string x{"[<(<(<(<{}))><([]([]()"};
    EXPECT_EQ(')',findFirstIllegalChar(x));
}

TEST(Y2021_Day10Example,Test1e) {
    string x{"<{([([[(<>()){}]>(<<{{"};
    EXPECT_EQ('>',findFirstIllegalChar(x));
}

TEST(Y2021_Day10Example,Test2) {
    vector<string> x{
        "[({(<(())[]>[[{[]{<()<>>",
        "[(()[<>])]({[<{<<[]>>(",
        "{([(<{}[<>[]}>{[]{[(<()>",
        "(((({<>}<{<{<>}{[]{[]{}",
        "[[<[([]))<([[{}[[()]]]",
        "[{[{({}]{}}([{[{{{}}([]",
        "{<[[]]>}<{[{[{[]{()[[[]",
        "[<(<(<(<{}))><([]([]()",
        "<{([([[(<>()){}]>(<<{{",
        "<{([{{}}[<[[[<>{}]]]>[]]"
    };
    EXPECT_EQ(26397,calcSyntaxScore(x));
}

TEST(Y2021_Day10Example,Test3a) {
    string x{"[({(<(())[]>[[{[]{<()<>>"};
    EXPECT_EQ(288957,calcIncompleteScore(x));
}

TEST(Y2021_Day10Example,Test3b) {
    string x{"[(()[<>])]({[<{<<[]>>("};
    EXPECT_EQ(5566,calcIncompleteScore(x));
}

TEST(Y2021_Day10Example,Test3c) {
    string x{"(((({<>}<{<{<>}{[]{[]{}"};
    EXPECT_EQ(1480781,calcIncompleteScore(x));
}

TEST(Y2021_Day10Example,Test3d) {
    string x{"{<[[]]>}<{[{[{[]{()[[[]"};
    EXPECT_EQ(995444,calcIncompleteScore(x));
}

TEST(Y2021_Day10Example,Test3e) {
    string x{"<{([{{}}[<[[[<>{}]]]>[]]"};
    EXPECT_EQ(294,calcIncompleteScore(x));
}

