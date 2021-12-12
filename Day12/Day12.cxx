//
//  Advent of Code 2021 Solutions: Day 12
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/11/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//

#include "Day12.h"
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
//#include <sstream>
//#include <thread>
//#include <tuple>
//#include <unordered_map>
#include <unordered_set>


using namespace std;
namespace AocDay12 {

    static const std::string InputFileName = "Day12.txt";
void findPath(const std::unordered_map<std::string,std::vector<std::string>>& connections, const std::string& cave, std::vector<std::string>& paths, unordered_set<std::string>& visited);
void findPath2(const std::unordered_map<std::string,std::vector<std::string>>& connections, const std::string& cave, std::vector<std::string>& paths, unordered_set<std::string>& visited, bool smallCavePassUsed);
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        auto connections = parseInput(input);
		return to_string(findPossiblePaths(connections).size());
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        auto connections = parseInput(input);
        return to_string(findPossiblePaths2(connections).size());
    }

std::unordered_map<std::string,std::vector<std::string>> parseInput(const std::vector<std::string>& input) {
    std::unordered_map<std::string,std::vector<std::string>> connections{};
    for(const auto& line : input) {
        auto itr = line.begin()+line.find("-");
        string d1{line.begin(),itr}, d2{itr+1,line.end()};
        connections[d1].push_back(d2);
        connections[d2].push_back(d1);
    }
    return connections;
}

std::vector<std::string> findPossiblePaths(const std::unordered_map<std::string,std::vector<std::string>>& connections) {
    std::vector<std::string> paths{"start"};
    unordered_set<std::string> visited{"start"};
    findPath(connections,"start",paths,visited);
//    printVector(paths);
    return paths;
}

void findPath(const std::unordered_map<std::string,std::vector<std::string>>& connections, const std::string& cave, std::vector<std::string>& paths, unordered_set<std::string>& visited) {
    vector<string> updatedPaths{};
    for(const auto& c : connections.at(cave)) {
        vector<string> newPaths{c};
        if(c == "start" || (c[0] >= 'a' && visited.count(c) > 0 )) {
            //already been here.
        } else {
            unordered_set<string> newVisits{visited};
            if(c[0] >= 'a') {
                newVisits.insert(c);
            }
            if(c == "end") {
                
            } else {
                findPath(connections, c, newPaths, newVisits);
            }
            for(const auto& s : newPaths) {
                updatedPaths.push_back(s);
            }
        }
    }
    
    vector<string> finalPaths{};
    for(auto& path : paths) {
        for(const auto& up : updatedPaths) {
            finalPaths.push_back(path+up);
        }
    }
    std::swap(finalPaths,paths);
}

std::vector<std::string> findPossiblePaths2(const std::unordered_map<std::string,std::vector<std::string>>& connections) {
    std::vector<std::string> paths{"start"};
    unordered_set<std::string> visited{"start"};
    findPath2(connections,"start",paths,visited,false);
//    printVector(paths);
    return paths;
}

void findPath2(const std::unordered_map<std::string,std::vector<std::string>>& connections, const std::string& cave, std::vector<std::string>& paths, unordered_set<std::string>& visited, bool smallCavePassUsed) {
    vector<string> updatedPaths{};
    for(const auto& c : connections.at(cave)) {
        vector<string> newPaths{c};
        bool passUsed{smallCavePassUsed};
        if(c == "start" || (c[0] >= 'a' && visited.count(c) > (passUsed ? 0 : 1))) {
            //already been here.
        } else {
            
            if(c == "end") {
                
            } else {
                unordered_set<string> newVisits{visited};
                if(c[0] >= 'a') {
                    if(!passUsed) {
                        passUsed = visited.count(c) > 0;
                    }
                    newVisits.insert(c);
                }
                findPath2(connections, c, newPaths, newVisits,passUsed);
            }
            for(const auto& s : newPaths) {
                updatedPaths.push_back(s);
            }
        }
    }
    
    vector<string> finalPaths{};
    finalPaths.reserve(paths.size()*updatedPaths.size());
    for(auto& path : paths) {
        for(const auto& up : updatedPaths) {
            finalPaths.emplace_back(path+up);
        }
    }
    std::swap(finalPaths,paths);
}
}
