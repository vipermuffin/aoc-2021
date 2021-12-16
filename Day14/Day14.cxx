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
//#include <array>
#include <climits>   //INT_MIN, INT_MAX, etc.
//#include <chrono>
//#include <iostream>
//#include <fstream> //ifstream
//#include <functional> //std::function
//#include <iomanip> //setfill setw hex
//#include <map>
//#include <math.h> //sqrt
//#include <numeric> //std::accumulate
//#include <queue>
//#include <regex>
//#include <set>
#include <sstream>
//#include <thread>
//#include <tuple>
//#include <unordered_map>
//#include <unordered_set>


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
		return to_string(countChars(result));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        auto start = input[0];
        vector<string> dbInput{input.begin()+2,input.end()};
        auto db = buildReplacementList2(dbInput);
        auto result = performSteps3(db, start, 40);
        return to_string(result);
    }
    
    std::unordered_map<std::string, std::string> buildReplacementList(const std::vector<std::string>& input) {
        unordered_map<string, string> db{};
        for(const auto& rule : input) {
            char in[3];
            char out[2];
            sscanf(rule.c_str(), "%s -> %s",in,out);
            auto outStr = string("---");
            outStr[0] = in[0];
            outStr[1] = out[0];
            outStr[2] = in[1];
            db[string(in)] = outStr;
        }
        
        return db;
    }
    
    std::string performSteps(std::unordered_map<std::string, std::string>& db, std::string startStr, int steps) {
        for(int i = 0; i < steps; i++) {
            string outputStr{};
            outputStr.resize(startStr.size()*2-1,'-');
            auto itr = startStr.begin();
            int64_t j = 0;
            while(itr!=startStr.end()) {
                if(std::next(itr) != startStr.end()) {
                    string strPair{itr,itr+2};
                    auto& s = db[strPair];
                    outputStr[j++] = s[0];
                    outputStr[j++] = s[1];
                    outputStr[j] = s[2];
                }
                itr++;
            }
            std::swap(outputStr, startStr);
        }
        
        return startStr;
    }

    int64_t countChars(const std::string& str) {
        unordered_map<char, int64_t> counts{};
        //Count the chars occurrence
        for(const auto& c : str) {
            counts[c]++;
        }
        //Find min/max
        int32_t maxVal{INT32_MIN}, minVal{INT32_MAX};
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
    
    std::unordered_map<std::string, std::string> buildReplacementList2(const std::vector<std::string>& input) {
        unordered_map<string, string> db{};
        for(const auto& rule : input) {
            char in[3];
            char out[2];
            sscanf(rule.c_str(), "%s -> %s",in,out);
            db[string(in)] = string(out);
        }
//        cout << '[';
//        for(const auto& kvp : db) {
//            cout << '{' << kvp.first << ',' << kvp.second << '}';
//        }
//        cout << '}' << endl;
        return db;
    }
    
    int64_t performSteps2(std::unordered_map<std::string, std::string>& db, std::string startStr, int steps) {
        unordered_map<char, int64_t> counts{};
        //initialize
        string tmpPair{"--"}, newPair{"--"};
        
        auto itr = startStr.begin();
        while(itr!=startStr.end()) {
            counts[*itr]++;
            if(std::next(itr) != startStr.end()) {
                tmpPair[0] = *itr;
                tmpPair[1] = *(std::next(itr));
                stepPair(db, counts, tmpPair, steps);
            }
            itr++;
        }
        
        //Find min/max
        int32_t maxVal{INT32_MIN}, minVal{INT32_MAX};
        for(const auto& kvp : counts) {
//            cout << "{" << kvp.first << ":" << kvp.second << "}" << endl;
            if(kvp.second > maxVal) {
                maxVal = kvp.second;
            }
            if(kvp.second < minVal) {
                minVal = kvp.second;
            }
        }
        return maxVal-minVal;
    }
    
//    cacheMap buildCache(std::unordered_map<std::string, std::string>& db, int steps) {
//
//    }
    
    void stepPair(std::unordered_map<std::string, std::string>& db, unordered_map<char, int64_t>& charCount, const std::string& pStr, int step) {
        
        if(--step >= 0) {
            string tmpPair{"--"};
            auto& newChar = db[pStr][0];
            charCount[newChar]++;
            tmpPair[0] = pStr[0];
            tmpPair[1] = newChar;
            stepPair(db, charCount, tmpPair, step);
            tmpPair[0] = newChar;
            tmpPair[1] = pStr[1];
            stepPair(db, charCount, tmpPair, step);
        }
    }
    
    uint64_t performSteps3(std::unordered_map<std::string, std::string>& db, std::string startStr, int steps) {
        unordered_map<char, uint64_t> counts{};
        //initialize
        string tmpPair{"--"}, newPair{"--"};
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
                auto s = db[kvp.first];
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
            //            cout << "{" << kvp.first << ":" << kvp.second << "}" << endl;
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
