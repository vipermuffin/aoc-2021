//
//  Advent of Code 2021 Tests: Day 4
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/03/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//

#include "Day04.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay04{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay04;

TEST(Y2021_SolveDay4, FinalSolutionPartA) {
    EXPECT_EQ("2745", solvea());
}

TEST(Y2021_SolveDay4, FinalSolutionPartB) {
    EXPECT_EQ("6594", solveb());
}

TEST(Y2021_Day4Example,GivenBoardTextThenParseGameBoard) {
    vector<string> game {
        "22 13 17 11  0",
        " 8  2 23  4 24",
        "21  9 14 16  7",
        " 6 10  3 18  5",
        " 1 12 20 15 19"
    };
    auto board = parseBoard(game);
    EXPECT_EQ(1,board[0].count(22));
    EXPECT_EQ(1,board[0].count(8));
    EXPECT_EQ(1,board[0].count(21));
    EXPECT_EQ(1,board[0].count(6));
    EXPECT_EQ(1,board[0].count(1));
    EXPECT_EQ(1,board[2].count(17));
    EXPECT_EQ(1,board[2].count(23));
    EXPECT_EQ(1,board[2].count(14));
    EXPECT_EQ(1,board[2].count(3));
    EXPECT_EQ(1,board[2].count(20));
    EXPECT_EQ(1,board[6].count(8));
    EXPECT_EQ(1,board[6].count(2));
    EXPECT_EQ(1,board[6].count(23));
    EXPECT_EQ(1,board[6].count(4));
    EXPECT_EQ(1,board[6].count(24));
}

TEST(Y2021_Day4Example,GivenBoardTextThenCreateAndTestBoardObject) {
    vector<string> game {
        "14 21 17 24  4",
        "10 16 15  9 19",
        "18  8 23 26 20",
        "22 11 13  6  5",
        " 2  0 12  3  7"
    };
    Board b{game};
    EXPECT_FALSE(b.hasWinner());
    b.newNumber(7);
    b.newNumber(4);
    b.newNumber(9);
    b.newNumber(5);
    b.newNumber(11);
    EXPECT_FALSE(b.hasWinner());
    b.newNumber(17);
    b.newNumber(23);
    b.newNumber(2);
    b.newNumber(0);
    b.newNumber(14);
    b.newNumber(21);
    EXPECT_FALSE(b.hasWinner());
    EXPECT_TRUE(b.newNumber(24));
    EXPECT_EQ(4512, b.getWinningResult());
}

TEST(Y2021_Day4Example,GivenTextWithMultipleBoardsThenParseGameBoards) {
    vector<string> game {
        "22 13 17 11  0",
        " 8  2 23  4 24",
        "21  9 14 16  7",
        " 6 10  3 18  5",
        " 1 12 20 15 19",
        "",
        " 3 15  0  2 22",
        " 9 18 13 17  5",
        "19  8  7 25 23",
        "20 11 10 24  4",
        "14 21 16 12  6",
        "",
        "14 21 17 24  4",
        "10 16 15  9 19",
        "18  8 23 26 20",
        "22 11 13  6  5",
        " 2  0 12  3  7"
    };
    auto boards = parseBoards(game);
    EXPECT_EQ(3,boards.size());
}

TEST(Y2021_Day4Example,GivenGameInputsThenPlayGame) {
    vector<int8_t> nums{7,4,9,5,11,17,23,2,0,14,21,24,10,16,13,6,15,25,12,22,18,20,8,19,3,26,1};
    vector<string> game {
        "22 13 17 11  0",
        " 8  2 23  4 24",
        "21  9 14 16  7",
        " 6 10  3 18  5",
        " 1 12 20 15 19",
        "",
        " 3 15  0  2 22",
        " 9 18 13 17  5",
        "19  8  7 25 23",
        "20 11 10 24  4",
        "14 21 16 12  6",
        "",
        "14 21 17 24  4",
        "10 16 15  9 19",
        "18  8 23 26 20",
        "22 11 13  6  5",
        " 2  0 12  3  7"
    };
    
    auto boards = parseBoards(game);
    EXPECT_EQ(4512,playGame(boards, nums));
}

TEST(Y2021_Day4Example,GivenRawInputThenVerifyPlayGame) {
    vector<string> game {
        "7,4,9,5,11,17,23,2,0,14,21,24,10,16,13,6,15,25,12,22,18,20,8,19,3,26,1",
        "",
        "22 13 17 11  0",
        " 8  2 23  4 24",
        "21  9 14 16  7",
        " 6 10  3 18  5",
        " 1 12 20 15 19",
        "",
        " 3 15  0  2 22",
        " 9 18 13 17  5",
        "19  8  7 25 23",
        "20 11 10 24  4",
        "14 21 16 12  6",
        "",
        "14 21 17 24  4",
        "10 16 15  9 19",
        "18  8 23 26 20",
        "22 11 13  6  5",
        " 2  0 12  3  7"
    };
    
    EXPECT_EQ(4512,playGame(game));
}

TEST(Y2021_Day4Example,GivenRawInputThenVerifyPlayGamePart2) {
    vector<string> game {
        "7,4,9,5,11,17,23,2,0,14,21,24,10,16,13,6,15,25,12,22,18,20,8,19,3,26,1",
        "",
        "22 13 17 11  0",
        " 8  2 23  4 24",
        "21  9 14 16  7",
        " 6 10  3 18  5",
        " 1 12 20 15 19",
        "",
        " 3 15  0  2 22",
        " 9 18 13 17  5",
        "19  8  7 25 23",
        "20 11 10 24  4",
        "14 21 16 12  6",
        "",
        "14 21 17 24  4",
        "10 16 15  9 19",
        "18  8 23 26 20",
        "22 11 13  6  5",
        " 2  0 12  3  7"
    };
    
    EXPECT_EQ(1924,playGame(game,true));
}
