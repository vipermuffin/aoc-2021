//
//  Advent of Code 2021 Solutions: Day 3
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/02/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//

#include "Day03.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.


using namespace std;
namespace AocDay03 {

    static const std::string InputFileName = "Day03.txt";
    
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        auto output = calculateGammaEpsilon(input);
		return to_string(output.first*output.second);
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        auto output = findO2CO2(input);
        return to_string(output.first*output.second);
    }

    std::pair<int32_t,int32_t> calculateGammaEpsilon(const std::vector<std::string>& input) {
        int32_t g{0},e{0};
        for(int i = 0; i < input[0].size(); i++) {
            g <<= 1;
            e <<= 1;
            int count{0};
            for(const auto& s : input) {
                count += s[i]=='1' ? 1 : 0;
            }
            if(count > input.size()/2) {
                g |= 1;
            } else {
                e |= 1;
            }
        }
        
        return make_pair(g, e);
    }
    
    int32_t findValue(const std::vector<std::string>& vals, bool useMostCommon) {
        auto cpy{vals};
        auto idx{0};
        
        while(cpy.size()>1 && idx<cpy.front().size()) {
            vector<string> tmp{};
            tmp.reserve(cpy.size());
            int count{0};
            for(const auto& s : cpy) {
                count += s[idx]=='1' ? 1 : 0;
            }
            auto count0 = cpy.size()-count;
            auto val = count >= count0 ? (useMostCommon ? 1 : 0) : (useMostCommon ? 0 : 1);
            char c = '0'+val;
            for(int i = 0; i < cpy.size();i++) {
                if(cpy[i][idx] == c) {
                    tmp.push_back(cpy[i]);
                }
            }
            idx++;
            std::swap(cpy,tmp);
        }
        return std::stoi(cpy.front(),nullptr,2);
    }
    
    std::pair<int32_t,int32_t> findO2CO2(const std::vector<std::string>& input) {
        return make_pair(findValue(input, true),findValue(input, false));
    }
}
