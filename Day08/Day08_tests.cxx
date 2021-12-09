//
//  Advent of Code 2021 Tests: Day 8
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/07/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//

#include "Day08.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay08{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay08;

TEST(Y2021_SolveDay8, FinalSolutionPartA) {
    EXPECT_EQ("383", solvea());
}

TEST(Y2021_SolveDay8, FinalSolutionPartB) {
    EXPECT_EQ("998900", solveb());
}

TEST(Y2021_Day8Example,Test1) {
    vector<string> x{
        "be cfbegad cbdgef fgaecd cgeb fdcge agebfd fecdb fabcd edb | fdgacbe cefdb cefbgd gcbe",
        "edbfga begcd cbg gc gcadebf fbgde acbgfd abcde gfcbed gfec | fcgedb cgb dgebacf gc",
        "fgaebd cg bdaec gdafb agbcfd gdcbef bgcad gfac gcb cdgabef | cg cg fdcagb cbg",
        "fbegcd cbd adcefb dageb afcb bc aefdc ecdab fgdeca fcdbega | efabcd cedba gadfec cb",
        "aecbfdg fbg gf bafeg dbefa fcge gcbea fcaegb dgceab fcbdga | gecf egdcabf bgf bfgea",
        "fgeab ca afcebg bdacfeg cfaedg gcfdb baec bfadeg bafgc acf | gebdcfa ecba ca fadegcb",
        "dbcfg fgd bdegcaf fgec aegbdf ecdfab fbedc dacgb gdcebf gf | cefg dcbef fcge gbcadfe",
        "bdfegc cbegaf gecbf dfcage bdacg ed bedf ced adcbefg gebcd | ed bcgafe cdgba cbgef",
        "egadfb cdbfeg cegd fecab cgb gbdefca cg fgcdab egfdb bfceg | gbdfcae bgc cg cgb",
        "gcafb gcf dcaebfg ecagb gf abcdeg gaef cafbge fdbac fegbdc | fgae cfgab fg bagce"
    };
    EXPECT_EQ(26,countEasyDigits(x));
}

TEST(Y2021_Day8Example,Test2) {
    string x{"acedgfb cdfbe gcdfa fbcad dab cefabd cdfgeb eafb cagedb ab | cdfeb fcadb cdfeb cdbaf"};
    auto digits = decodeDigits(x);
    EXPECT_EQ("acedgfb",digits["8"]);
    EXPECT_EQ("cdfbe",digits["5"]);
    EXPECT_EQ("gcdfa",digits["2"]);
    EXPECT_EQ("fbcad",digits["3"]);
    EXPECT_EQ("dab",digits["7"]);
    EXPECT_EQ("cefabd",digits["9"]);
    EXPECT_EQ("cdfgeb",digits["6"]);
    EXPECT_EQ("eafb",digits["4"]);
    EXPECT_EQ("cagedb",digits["0"]);
    EXPECT_EQ("ab",digits["1"]);
}

TEST(Y2021_Day8Example,Test3) {
    string x{"acedgfb cdfbe gcdfa fbcad dab cefabd cdfgeb eafb cagedb ab | cdfeb fcadb cdfeb cdbaf"};
    auto digits = getOutputVal(x);
    EXPECT_EQ(5353, digits);
}

TEST(Y2021_Day8Example,Test4) {
    vector<string> x{
        "be cfbegad cbdgef fgaecd cgeb fdcge agebfd fecdb fabcd edb | fdgacbe cefdb cefbgd gcbe",
        "edbfga begcd cbg gc gcadebf fbgde acbgfd abcde gfcbed gfec | fcgedb cgb dgebacf gc",
        "fgaebd cg bdaec gdafb agbcfd gdcbef bgcad gfac gcb cdgabef | cg cg fdcagb cbg",
        "fbegcd cbd adcefb dageb afcb bc aefdc ecdab fgdeca fcdbega | efabcd cedba gadfec cb",
        "aecbfdg fbg gf bafeg dbefa fcge gcbea fcaegb dgceab fcbdga | gecf egdcabf bgf bfgea",
        "fgeab ca afcebg bdacfeg cfaedg gcfdb baec bfadeg bafgc acf | gebdcfa ecba ca fadegcb",
        "dbcfg fgd bdegcaf fgec aegbdf ecdfab fbedc dacgb gdcebf gf | cefg dcbef fcge gbcadfe",
        "bdfegc cbegaf gecbf dfcage bdacg ed bedf ced adcbefg gebcd | ed bcgafe cdgba cbgef",
        "egadfb cdbfeg cegd fecab cgb gbdefca cg fgcdab egfdb bfceg | gbdfcae bgc cg cgb",
        "gcafb gcf dcaebfg ecagb gf abcdeg gaef cafbge fdbac fegbdc | fgae cfgab fg bagce"
    };
    EXPECT_EQ(61229,SumOutputVals(x));
}
