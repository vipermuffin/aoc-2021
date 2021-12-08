//
//  Advent of Code 2021 Solutions: Day 8
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/07/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//

#include "Day08.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <numeric> //std::accumulate
#include <unordered_map>

using namespace std;
namespace AocDay08 {

    static const std::string InputFileName = "Day08.txt";
    bool findOverlapCount(std::vector<std::string>& strs, const string& str2Find, int32_t overLapCnt);
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);

		return to_string(countEasyDigits(input));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);

		return to_string(SumOutputVals(input));
    }
    
    int32_t countEasyDigits(const std::vector<std::string>& digits) {
        unordered_map<size_t, int32_t> counts{};
        for(const auto& line : digits) {
            auto words = parseLineForWords(line);
            auto itr = words.begin();
            while(itr != words.end() && *itr != "|") {
                itr++;
            }
            itr++;
            while(itr != words.end()) {
                counts[itr++->size()]++;
            }
        }
        return counts[2]+counts[3]+counts[4]+counts[7];
    }
    
    std::unordered_map<std::string, std::string> decodeDigits(const std::string& line) {
        unordered_map<string, string> digits{};
        unordered_map<size_t, vector<string>> tbdCodes{};
        auto words = parseLineForWords(line);
        auto itr = words.begin();
        while(itr != words.end() && *itr != "|") {
            tbdCodes[itr->size()].push_back(*itr);
            itr++;
        }
        //populate known digits
        digits["1"] = tbdCodes[2].back();
        digits["4"] = tbdCodes[4].back();
        digits["7"] = tbdCodes[3].back();
        digits["8"] = tbdCodes[7].back();
        
        //Find 6.  Should not match 1
        findOverlapCount(tbdCodes[6],digits["1"],1);
        digits["6"] = tbdCodes[6].back();
        tbdCodes[6].pop_back();
        
        //Find 0 & 9
        findOverlapCount(tbdCodes[6],digits["4"],3);
        digits["0"] = tbdCodes[6].back();
        tbdCodes[6].pop_back();
        digits["9"] = tbdCodes[6].back();
        
        //Find 3
        findOverlapCount(tbdCodes[5], digits["1"], 2);
        digits["3"] = tbdCodes[5].back();
        tbdCodes[5].pop_back();
        findOverlapCount(tbdCodes[5], digits["4"], 3);
        digits["5"] = tbdCodes[5].back();
        tbdCodes[5].pop_back();
        digits["2"] = tbdCodes[5].back();
        return digits;
    }
    
    bool findOverlapCount(std::vector<std::string>& strs, const string& str2Find, int32_t overLapCnt) {
        bool found = false;
        while(!found) {
            std::rotate(strs.begin(), strs.begin()+1, strs.end());
            auto s = strs.back();
            auto sItr = str2Find.begin();
            int32_t count{0};
            while(sItr != str2Find.end()) {
                if(s.find(*sItr++) != string::npos) {
                    count++;
                }
            }
            found = count == overLapCnt;
        }
        return found;
    }
    
    int32_t getOutputVal(const std::string& line) {
        auto db = decodeDigits(line);
        unordered_map<string, int32_t> decodeMap{};
        for(const auto& kvp : db) {
            auto s{kvp.second};
            std::sort(s.begin(),s.end());
            decodeMap[s] = stoi(kvp.first);
        }
        string outputStr{line.begin()+line.find("|")+1,line.end()};
        auto digits = parseLineForWords(outputStr);
        int32_t outVal{0};
        for(int i = 0; i < digits.size();i++) {
            auto s{digits[i]};
            std::sort(s.begin(), s.end());
            outVal *= 10;
            outVal += decodeMap[s];
        }
        return outVal;
    }

    int32_t SumOutputVals(const std::vector<std::string>& lines) {
        vector<int32_t> vals{};
        for(const auto& line : lines) {
            vals.push_back(getOutputVal(line));
        }
        return std::accumulate(vals.begin(),vals.end(),0);
    }
}
