//
//  Advent of Code 2021 Solutions: Day 10
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/09/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//

#include "Day10.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <functional> //std::function
#include <numeric> //std::accumulate
#include <unordered_map>

using namespace std;
namespace AocDay10 {
    static const std::string InputFileName = "Day10.txt";
    const unordered_map<char, char> matches{{')','('},{']','['},{'}','{'},{'>','<'}};

    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
		return to_string(calcSyntaxScore(input));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        vector<int64_t> scores{};
        for(const auto& line : input) {
            auto score = calcIncompleteScore(line);
            if(score > 0) {
                scores.push_back(score);
            }
        }
        std::sort(scores.begin(),scores.end());
        auto i = scores.size()/2;
		return to_string(scores[i]);
    }

    char findFirstIllegalChar(const std::string& line) {
        auto itr = line.begin();
        vector<char> stack{};
        
        while(itr != line.end()) {
            if(matches.count(*itr) == 0) {
                stack.push_back(*itr);
            } else {
                if(stack.back() == matches.at(*itr)) {
                    stack.pop_back();
                } else {
                    return *itr;
                }
            }
            itr++;
        }
        return '0';
    }

    int64_t calcSyntaxScore(const std::vector<std::string>& lines) {
        unordered_map<char, int64_t> values {{'0',0},{')',3},{']',57},{'}',1197},{'>',25137}};
        vector<int64_t> vals{};
        vals.reserve(lines.size());
        for(const auto& line : lines) {
            vals.push_back(values[findFirstIllegalChar(line)]);
        }
        
        return std::accumulate(vals.begin(), vals.end(), static_cast<int64_t>(0));
    }

    int64_t calcIncompleteScore(const std::string& line) {
        unordered_map<char, int64_t> values {{'(',1},{'[',2},{'{',3},{'<',4}};
        vector<char> stack{};
        
        auto itr = line.begin();
        while(itr != line.end()) {
            if(matches.count(*itr) == 0) {
                stack.push_back(*itr);
            } else {
                if(stack.back() == matches.at(*itr)) {
                    stack.pop_back();
                } else {
                    return 0;
                }
            }
            itr++;
        }
        
        int64_t score = 0;
        auto rItr = stack.rbegin();
        while(rItr != stack.rend()) {
            score *= 5;
            score += values[*rItr++];
        }
        return score;
    }
}
