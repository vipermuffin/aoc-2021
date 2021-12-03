//
//  Advent of Code 2021 Solutions: Day 2
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/01/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//

#include "Day02.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <functional> //std::function
#include <unordered_map>


using namespace std;
namespace AocDay02 {

    static const std::string InputFileName = "Day02.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        auto output = followPath(input);
		return to_string(output.first*output.second);
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        auto output = followPath(input,true);
        return to_string(output.first*output.second);
    }

    std::pair<int32_t,int32_t> followPath(const std::vector<std::string>& ins, bool useAim) {
        int32_t x{0},y{0},y2{0};
        unordered_map<string, std::function<void(int32_t)>> ops = {
            {"forward",[&](int32_t val){x+=val;y2+=y*val;}},
            {"down",[&](int32_t val){y+=val;}},
            {"up",[&](int32_t val){y-=val;}}
        };
        
        for(const auto& s: ins) {
            auto op = parseLineForWords(s);
            ops[op[0]](stoi(op[1]));
        }
        
        return make_pair(x, useAim ? y2: y);
    }
}
