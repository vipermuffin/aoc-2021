//
//  Advent of Code 2021 Solutions: Day 14
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/14/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//

#include "Day14.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.


using namespace std;
namespace AocDay14 {
    using cacheMap = unordered_map<string, vector<unordered_map<char,int64_t>>>;
    static const std::string InputFileName = "Day14.txt";
    void stepPair(std::unordered_map<std::string, std::string>&, unordered_map<char, int64_t>&, const std::string& pStr, int step);
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        auto start = input[0];
        vector<string> dbInput{input.begin()+2,input.end()};
        auto db = buildReplacementList(dbInput);
        auto result = performSteps(db, start, 10);
		return to_string(result);
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        auto start = input[0];
        vector<string> dbInput{input.begin()+2,input.end()};
        auto db = buildReplacementList(dbInput);
        auto result = performSteps(db, start, 40);
        return to_string(result);
    }
    
    std::unordered_map<std::string, std::string> buildReplacementList(const std::vector<std::string>& input) {
        unordered_map<string, string> db{};
        for(const auto& rule : input) {
            char in[3], out[2];
            sscanf(rule.c_str(), "%s -> %s",in,out);
            db[string(in)] = string(out);
        }
        return db;
    }
  
    uint64_t performSteps(std::unordered_map<std::string, std::string>& db, std::string startStr, int steps) {
        unordered_map<char, uint64_t> counts{};
        //initialize
        string tmpPair{"--"};
        unordered_map<string, uint64_t> pairMap{};
        auto itr = startStr.begin();
        while(itr!=startStr.end()) {
            counts[*itr]++;
            if(std::next(itr) != startStr.end()) {
                tmpPair[0] = *itr;
                tmpPair[1] = *(std::next(itr));
                pairMap[tmpPair]++;
            }
            itr++;
        }
        
        for(int i = 0; i < steps; i++) {
            unordered_map<string, uint64_t> newMap{};
            for(const auto& kvp : pairMap) {
                const auto& s = db[kvp.first];
                counts[s[0]] += kvp.second;
                tmpPair[0] = kvp.first[0];
                tmpPair[1] = s[0];
                newMap[tmpPair] += kvp.second;
                
                tmpPair[0] = s[0];
                tmpPair[1] = kvp.first[1];
                newMap[tmpPair] += kvp.second;
            }
            std::swap(pairMap,newMap);
        }
        
        //Find min/max
        uint64_t maxVal{0}, minVal{UINT64_MAX};
        for(const auto& kvp : counts) {
            if(kvp.second > maxVal) {
                maxVal = kvp.second;
            }
            if(kvp.second < minVal) {
                minVal = kvp.second;
            }
        }
        return maxVal-minVal;
    }
}
