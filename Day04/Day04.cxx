//
//  Advent of Code 2021 Solutions: Day 4
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/03/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//

#include "Day04.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <numeric> //std::accumulate

using namespace std;
namespace AocDay04 {

    static const std::string InputFileName = "Day04.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
		return to_string(playGame(input));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
		return to_string(playGame(input,true));
    }

    boardGroup parseBoards(const std::vector<std::string>& input) {
        boardGroup boards{};
        boards.reserve(input.size()/5);
        auto bStart = input.begin();
        while(bStart != input.end()) {
            auto bEnd = bStart;
            while(bEnd != input.end() && bEnd->size() != 0) {
                bEnd++;
            }
            vector<string> boardInput{bStart,bEnd};
            boards.emplace_back(boardInput);
            if(bEnd != input.end()) {
                bEnd++;
            }
            bStart = bEnd;
        }
        return boards;
    }

    board_t parseBoard(const std::vector<std::string>& input) {
        //Columns will be the first five sets and rows will be the last five
        board_t b{{},{},{},{},{},{},{},{},{},{}};
        int rowIdx = 5;
        for(const auto& s: input) {
            auto nums = parseLineForNumbers(s);
            for(int i = 0; i < nums.size(); i++) {
                b[i].insert(nums[i]);
                b[rowIdx].insert(nums[i]);
            }
            rowIdx++;
        }
        return b;
    }

    Board::Board(const std::vector<std::string>& input) :
    _count{}, _winningNum{-1}, _winningIdx{-1} {
        _b = parseBoard(input);
        _count.resize(_b.size(),0);
    }

    bool Board::newNumber(int8_t x) {
        _playedNums.insert(x);
        for(int i = 0; i < _b.size(); i++) {
            if(_b[i].count(x) > 0) {
                _count[i]++;
                if(_count[i] == 5) {
                    _winningNum = x;
                    _winningIdx = i;
                    return true;
                }
            }
        }
        return false;
    }

    bool Board::hasWinner() const{
        return _winningNum != -1;
    }

    int32_t Board::getWinningResult() const {
        //Find unmarked
        unordered_set<int8_t> unmarked{};
        for(const auto& s : _b) {
            for(const auto& x : s) {
                if(_playedNums.count(x) == 0) {
                    unmarked.insert(x);
                }
            }
        }
        auto sum = std::accumulate(unmarked.begin(),unmarked.end(),0);
        return sum*_winningNum;
    }

    int32_t playGame(const std::vector<std::string>& input, bool playThrough) {
        auto itr = input.begin();
        //Pull out the drawn numbers
        auto numInts = parseCsvLineForNum(*itr);
        vector<int8_t> nums{};
        for_each(numInts.begin(),numInts.end(),[&nums](const int x){nums.push_back(static_cast<int8_t>(x));});
        
        //Skip to start of first board and parse out boards
        itr++;itr++;
        vector<string> boardInput{itr,input.end()};
        auto boards = parseBoards(boardInput);
        return playGame(boards,nums,playThrough);
    }

    int32_t playGame(boardGroup& boards, const std::vector<int8_t>& numbers, bool playThrough) {
        auto numItr = numbers.begin();
        int winnersLeft = boards.size();
        while(numItr != numbers.end()) {
            for(auto& b : boards) {
                if(!b.hasWinner()) {
                    if(b.newNumber(*numItr)) {
                        //retrn right away if not finding the last winner
                        if(!playThrough || winnersLeft == 1)
                            return b.getWinningResult();
                        winnersLeft--;
                    }
                }
            }
            numItr++;
        }
        return -1;
    }
}
