//
//  Advent of Code 2021 Tests: Day 14
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/14/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//

#include "Day14.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay14{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay14;

TEST(Y2021_SolveDay14, FinalSolutionPartA) {
    EXPECT_EQ("2321", solvea());
}

TEST(Y2021_SolveDay14, FinalSolutionPartB) {
    EXPECT_EQ("2399822193707", solveb());
}

TEST(Y2021_Day14Example,Test1) {
    vector<string> x{
        "CH -> B",
        "HH -> N",
        "CB -> H",
        "NH -> C",
        "HB -> C",
        "HC -> B",
        "HN -> C",
        "NN -> C",
        "BH -> H",
        "NC -> B",
        "NB -> B",
        "BN -> B",
        "BB -> N",
        "BC -> B",
        "CC -> N",
        "CN -> C"
    };
    auto db = buildReplacementList(x);
    
    EXPECT_EQ(16,db.size());
    ASSERT_FALSE(db.count("CH")==0);
    EXPECT_EQ("B", db.at("CH"));
}

TEST(Y2021_Day14Example,Test2) {
    vector<string> x{
        "CH -> B",
        "HH -> N",
        "CB -> H",
        "NH -> C",
        "HB -> C",
        "HC -> B",
        "HN -> C",
        "NN -> C",
        "BH -> H",
        "NC -> B",
        "NB -> B",
        "BN -> B",
        "BB -> N",
        "BC -> B",
        "CC -> N",
        "CN -> C"
    };
    auto db = buildReplacementList(x);
    string start{"NNCB"};
    auto result = performSteps(db, start, 1);
    EXPECT_EQ(1,result);//"NCNBCHB"
    result = performSteps(db, start, 2);
    EXPECT_EQ(5,result);//"NBCCNBBBCBHCB"
    result = performSteps(db, start, 3);
    EXPECT_EQ(11-4,result);//"NBBBCNCCNBBNBNBBCHBHHBCHB"11-4
    result = performSteps(db, start, 4);
    EXPECT_EQ(23-5,result);//"NBBNBNBBCCNBCNCCNBBNBBNBBBNBBNBBCBHCBHHNHCBBCBHCB"
}

TEST(Y2021_Day14Example,Test3) {
    vector<string> x{
        "CH -> B",
        "HH -> N",
        "CB -> H",
        "NH -> C",
        "HB -> C",
        "HC -> B",
        "HN -> C",
        "NN -> C",
        "BH -> H",
        "NC -> B",
        "NB -> B",
        "BN -> B",
        "BB -> N",
        "BC -> B",
        "CC -> N",
        "CN -> C"
    };
    auto db = buildReplacementList(x);
    string start{"NNCB"};
    auto result = performSteps(db, start, 10);
    EXPECT_EQ(1588,result);
}

TEST(Y2021_Day14Example,Test4) {
    vector<string> x{
        "CH -> B",
        "HH -> N",
        "CB -> H",
        "NH -> C",
        "HB -> C",
        "HC -> B",
        "HN -> C",
        "NN -> C",
        "BH -> H",
        "NC -> B",
        "NB -> B",
        "BN -> B",
        "BB -> N",
        "BC -> B",
        "CC -> N",
        "CN -> C"
    };
    auto db = buildReplacementList(x);
    string start{"NNCB"};
    auto result = performSteps(db, start, 40);
    EXPECT_EQ(2188189693529,result);
}
