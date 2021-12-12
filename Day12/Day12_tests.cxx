//
//  Advent of Code 2021 Tests: Day 12
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/11/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//

#include "Day12.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay12{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay12;

TEST(Y2021_SolveDay12, FinalSolutionPartA) {
    EXPECT_EQ("3369", solvea());
}

TEST(Y2021_SolveDay12, FinalSolutionPartB) {
    EXPECT_EQ("85883", solveb());
}

TEST(Y2021_Day12Example,TestParseInput) {
    vector<string> x {
        "start-A",
        "start-b",
        "A-c",
        "A-b",
        "b-d",
        "A-end",
        "b-end"
    };
    auto connections = parseInput(x);
    ASSERT_EQ(2,connections["start"].size());
    std::sort(connections["start"].begin(),connections["start"].end());
    EXPECT_EQ("A", connections["start"][0]);
    EXPECT_EQ("b", connections["start"][1]);
}

TEST(Y2021_Day12Example,Test2) {
    vector<string> x {
        "start-A",
        "start-b",
        "A-c",
        "A-b",
        "b-d",
        "A-end",
        "b-end"
    };
    auto connections = parseInput(x);
    auto paths = findPossiblePaths(connections);
    EXPECT_EQ(10,paths.size());
}

TEST(Y2021_Day12Example,Test3) {
    vector<string> x {
        "dc-end",
        "HN-start",
        "start-kj",
        "dc-start",
        "dc-HN",
        "LN-dc",
        "HN-end",
        "kj-sa",
        "kj-HN",
        "kj-dc"
    };
    auto connections = parseInput(x);
    auto paths = findPossiblePaths(connections);
    EXPECT_EQ(19,paths.size());
}

TEST(Y2021_Day12Example,Test4) {
    vector<string> x {
        "fs-end",
        "he-DX",
        "fs-he",
        "start-DX",
        "pj-DX",
        "end-zg",
        "zg-sl",
        "zg-pj",
        "pj-he",
        "RW-he",
        "fs-DX",
        "pj-RW",
        "zg-RW",
        "start-pj",
        "he-WI",
        "zg-he",
        "pj-fs",
        "start-RW"
    };
    auto connections = parseInput(x);
    auto paths = findPossiblePaths(connections);
    EXPECT_EQ(226,paths.size());
}

TEST(Y2021_Day12Example,Test2b) {
    vector<string> x {
        "start-A",
        "start-b",
        "A-c",
        "A-b",
        "b-d",
        "A-end",
        "b-end"
    };
    auto connections = parseInput(x);
    auto paths = findPossiblePaths2(connections);
    EXPECT_EQ(36,paths.size());
}

TEST(Y2021_Day12Example,Test3b) {
    vector<string> x {
        "dc-end",
        "HN-start",
        "start-kj",
        "dc-start",
        "dc-HN",
        "LN-dc",
        "HN-end",
        "kj-sa",
        "kj-HN",
        "kj-dc"
    };
    auto connections = parseInput(x);
    auto paths = findPossiblePaths2(connections);
    EXPECT_EQ(103,paths.size());
}

TEST(Y2021_Day12Example,Test4b) {
    vector<string> x {
        "fs-end",
        "he-DX",
        "fs-he",
        "start-DX",
        "pj-DX",
        "end-zg",
        "zg-sl",
        "zg-pj",
        "pj-he",
        "RW-he",
        "fs-DX",
        "pj-RW",
        "zg-RW",
        "start-pj",
        "he-WI",
        "zg-he",
        "pj-fs",
        "start-RW"
    };
    auto connections = parseInput(x);
    auto paths = findPossiblePaths2(connections);
    EXPECT_EQ(3509,paths.size());
}
