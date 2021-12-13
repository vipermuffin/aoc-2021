//
//  Advent of Code 2021 Solutions: Day 13
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/12/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//

#include "Day13.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
//#include <array>
#include <climits>   //INT_MIN, INT_MAX, etc.


using namespace std;
namespace AocDay13 {

    static const std::string InputFileName = "Day13.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        auto grid = parseInputGrid(input);
        auto itr = input.begin();
        while(itr->find("=") == string::npos) {
            itr++;
        }
        auto newGrid = performFold(grid, *itr);
        
		return to_string(countDots(newGrid));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        auto grid = parseInputGrid(input);
        auto itr = input.begin();
        while(itr->find("=") == string::npos) {
            itr++;
        }
        while(itr != input.end()) {
            auto newGrid = performFold(grid, *itr);
            itr++;
            std::swap(grid,newGrid);
        }
        cout << endl;
        for(const auto& row : grid) {
            for(const auto& bit : row) {
                cout << (bit ? '#' : ' ');
            }
            cout << endl;
        }
		return "---";
    }

std::vector<std::vector<bool>> parseInputGrid(const std::vector<std::string>& input) {
    auto itr = input.begin();
    
    //Parse List of coordinates and determine bounds
    vector<std::pair<int,int>> xyPairs{};
    xyPairs.reserve(input.size());
    int xMax{INT_MIN},yMax{INT_MIN};
    while(itr != input.end() && itr->size() != 0) {
        int x,y;
        sscanf(itr->c_str(), "%d,%d",&x,&y);
        xyPairs.emplace_back(x,y);
        if(x > xMax) {
            xMax = x;
        }
        if(y > yMax) {
            yMax = y;
        }
        itr++;
    }
    
    //Build the grid
    std::vector<std::vector<bool>> grid{};
    grid.reserve(yMax);
    vector<bool> add{};
    add.resize(xMax+1);
    for(int i = 0; i <= yMax; i++) {
        grid.push_back(add);
    }
    
    //Update Grid
    for(const auto& p : xyPairs) {
        grid[p.second][p.first] = true;
    }
    
    return grid;
}

std::vector<std::vector<bool>> performFold(const std::vector<std::vector<bool>>& grid, const std::string& foldInstruction) {
    int foldLine{-1};
    bool foldIsHorizontal{false};
    
    if(foldInstruction.find("x=") == string::npos) {
        //y= instruction --> horizontal fold up
        sscanf(foldInstruction.c_str(), "fold along y=%d",&foldLine);
        foldIsHorizontal = true;
    } else {
        //x= instruction --> vertical fold left
        sscanf(foldInstruction.c_str(), "fold along x=%d",&foldLine);
    }
    
    std::vector<std::vector<bool>> newGrid{};
    if(foldIsHorizontal) {
        newGrid.reserve(foldLine);
        for(int i = 0; i < foldLine; i++) {
            newGrid.push_back(grid[i]);
        }
        auto topItr = newGrid.begin();
        auto botItr = std::prev(grid.end());
        auto itrEnd = grid.begin()+foldLine;
        while(botItr != itrEnd) {
            for(int x = 0; x < botItr->size(); x++) {
                (*topItr)[x] = topItr->at(x) || botItr->at(x);
            }
            botItr = std::prev(botItr);
            topItr = std::next(topItr);
        }
    } else {
        newGrid.reserve(grid.size());
        vector<bool> newRow{};
        newRow.resize(foldLine);
        for(int i = 0; i < grid.size(); i++) {
            newGrid.push_back(newRow);
            auto itr = newGrid[i].begin();
            auto lItr = grid[i].begin();
            auto rItr = grid[i].rbegin();
            auto endItr = newGrid[i].end();
            while(itr != endItr) {
                *itr = *lItr || *rItr;
                itr++;
                lItr++;
                rItr++;
            }
        }
    }
    
    return newGrid;
}

int countDots(const std::vector<std::vector<bool>>& grid) {
    int count{0};
    for(const auto& row : grid) {
        for(const auto& bit : row) {
            count += bit ? 1 : 0;
        }
    }
    return count;
}
}
