//
//  Advent of Code 2021 Solutions: Day 22
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/22/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//

#include "Day22.h"
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
//#include <unordered_set>


using namespace std;
namespace AocDay22 {

    static const std::string InputFileName = "Day22.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        auto grid = generatePointGrid(input);
		return to_string(countOnPoints(grid));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);

		return "---";
    }

void updatePointGrid(std::unordered_map<uint64_t, bool>& pointGrid, const std::string& ins, const bool init) {
    int32_t x1{0}, x2{0}, y1{0}, y2{0}, z1{0}, z2{0};
    PointInfo_t tmpPoint{0};
    bool isOn{false};
    tmpPoint.all = 0;
    if(ins.find("on") != string::npos) {
        (void)sscanf(ins.c_str(), "on x=%d..%d,y=%d..%d,z=%d..%d",&x1,&x2,&y1,&y2,&z1,&z2);
        isOn = true;
    } else {
        (void)sscanf(ins.c_str(), "off x=%d..%d,y=%d..%d,z=%d..%d",&x1,&x2,&y1,&y2,&z1,&z2);
        isOn = false;
    }
    if(!init || ((x1>=-50 && x2<50 && y1>=-50 && y2<=50 && z1>=-50 && z2 <=50))) {
        for(int32_t x = x1; x <= x2; x++) {
            tmpPoint.p.x = x;
            for(int32_t y = y1; y <= y2; y++) {
                tmpPoint.p.y = y;
                for(int32_t z = z1; z <= z2; z++) {
                    tmpPoint.p.z = z;
                    pointGrid[tmpPoint.all] = isOn;
                }
            }
        }
    }
}

int64_t countOnPoints(std::unordered_map<uint64_t, bool>& pointGrid) {
    return count_if(pointGrid.begin(),pointGrid.end(),[](std::pair<uint64_t,bool> x)->bool{return x.second;});
}

std::unordered_map<uint64_t, bool> generatePointGrid(const std::vector<std::string>& instructions, const bool init) {
    std::unordered_map<uint64_t, bool> grid{};
    for(const auto& line : instructions) {
        updatePointGrid(grid, line, init);
    }
    return grid;
}

}
