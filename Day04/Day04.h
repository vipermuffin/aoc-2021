//
//  Advent of Code 2021 Solutions: Day 4
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/03/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>
#include <unordered_set>

namespace AocDay04 {
//Function Definitions
class Board;
using board_t = std::vector<std::unordered_set<int8_t>>;
using boardGroup = std::vector<Board>;

board_t parseBoard(const std::vector<std::string>&);
boardGroup parseBoards(const std::vector<std::string>&);
int32_t playGame(const std::vector<std::string>&, bool playThrough = false);
int32_t playGame(boardGroup&, const std::vector<int8_t>&, bool playThrough = false);

class Board {
public:
    Board(const std::vector<std::string>&);
    ~Board() = default;
    bool newNumber(int8_t);
    bool hasWinner() const;
    int32_t getWinningResult() const;
protected:
    board_t _b;
    std::vector<int8_t> _count;
    std::unordered_set<int8_t> _playedNums;
    int8_t _winningNum;
    int8_t _winningIdx;
};
}
