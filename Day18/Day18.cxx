//
//  Advent of Code 2021 Solutions: Day 18
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/18/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//

#include "Day18.h"
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
namespace AocDay18 {

    static const std::string InputFileName = "Day18.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);

		return "---";
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);

		return "---";
    }

SnailfishNumber::SnailfishNumber() : parent{nullptr},x{nullptr},y{nullptr},xVal{0},yVal{0} {}
SnailfishNumber::SnailfishNumber(const std::string& numStr, SnailfishNumber* p) : parent{p},x{nullptr},y{nullptr},xVal{0},yVal{0} {
    
    if(count(numStr.begin(), numStr.end(), ',') == 1) {
        //not a nested value
        auto commaItr = numStr.begin()+numStr.find(",");
        sscanf(numStr.c_str(), "[%d,%d]",&xVal,&yVal);
    } else {
        //There are some nested values
        auto itr = std::next(numStr.begin());
        if(*itr =='[') {
            auto count = 1;
            itr++;
            //x is nested
            while(itr != numStr.end() && count > 0) {
                if(*itr == '[') {
                    count++;
                } else if (*itr == ']') {
                    count--;
                }
                itr++;
            }
            x = new SnailfishNumber(string(std::next(numStr.begin()),itr), this);
            itr++;
        } else {
            //x is not nested
            auto commaItr = numStr.begin()+numStr.find(",");
            xVal = stoi(string(itr,commaItr));
            itr = std::next(commaItr);
        }
        auto yStart = itr;
        string yStr{itr,numStr.end()};
        auto yitr = yStr.begin();
        if(*yitr =='[') {
            yitr++;
            auto count = 1;
            //y is nested
            while(yitr != yStr.end() && count > 0) {
                if(*yitr == '[') {
                    count++;
                } else if (*yitr == ']') {
                    count--;
                }
                yitr++;
            }
            y = new SnailfishNumber(string(yStr.begin(),yitr), this);
        } else {
            //y is not nested
            auto stopItr = yStr.begin()+yStr.find("]");
            yVal = stoi(string(yitr,stopItr));
        }
    }
}
SnailfishNumber::SnailfishNumber(const int x, const int y,SnailfishNumber* p) : parent{p},x{nullptr},y{nullptr},xVal{x},yVal{y} {}

SnailfishNumber::SnailfishNumber(const SnailfishNumber& copy, SnailfishNumber* p) : parent{p},x{nullptr},y{nullptr},xVal{copy.xVal},yVal{copy.yVal} {
    if(copy.x != nullptr) {
        x = new SnailfishNumber(*copy.x, this);
    }
    if(copy.y != nullptr) {
        y = new SnailfishNumber(*copy.y, this);
    }
}

SnailfishNumber::~SnailfishNumber() {
    delete x;
    x = nullptr;
    delete y;
    y = nullptr;
}

void SnailfishNumber::operator+=(SnailfishNumber &rhs) {
    SnailfishNumber newX{*this};
    delete x;
    x = new SnailfishNumber{newX};
    delete y;
    y = new SnailfishNumber{rhs};
}

void SnailfishNumber::reduce() {
    //Perform Explodes
    int xExp{-1},yExp{-1};
    while(this->explode(0, &xExp, &yExp)) {
//        cout << this->toString();
        xExp = -1;
        yExp = -1;
    }
//    SnailfishNumber* nextSN{nullptr};
//    SnailfishNumber* prevSN{nullptr};
//    int levelCount = 0;
//    nextSN = this->x;
//    while(nextSN != nullptr && levelCount < 3) {
//        prevSN = nextSN;
//        nextSN = nextSN->x;
//        levelCount++;
//    }
//    if(levelCount == 3) {
//        cout << "Explode: " << nextSN->toString();
//    }
}

int SnailfishNumber::magnitude() const {
    int xMag{xVal},yMag{yVal};
    if(x != nullptr) {
        xMag = x->magnitude();
    }
    if(y != nullptr) {
        yMag = y->magnitude();
    }
    return 3*xMag+2*yMag;
}

std::string SnailfishNumber::toString() const {
    stringstream ss{};
    ss << "[";
    if(x==nullptr) {
        ss << xVal;
    } else {
        ss << x->toString();
    }
    ss << ",";
    if(y==nullptr) {
        ss << yVal;
    } else {
        ss << y->toString();
    }
    ss << "]";
    return ss.str();
}

bool SnailfishNumber::explode(int level, int *xPtr, int *yPtr) {
    bool retVal = false;
    if(level > 3) {
        *xPtr = xVal;
        *yPtr = yVal;
        parent->applyExplosion(xPtr, yPtr, true);
        return true;
    } else {
        if(x != nullptr) {
            if(x->explode(level+1, xPtr, yPtr)) {
                delete x;
                x = nullptr;
                xVal = 0;
            }
        }
        if(y != nullptr) {
            if(y->explode(level+1, xPtr, yPtr)) {
                delete y;
                y = nullptr;
                yVal = 0;
            }
        }
        
    }
    return retVal;
}

bool SnailfishNumber::applyExplosion(int *xPtr, int *yPtr, bool direction) {
    if(xPtr != nullptr) {
        if(x == nullptr) {
            xVal += *xPtr;
            *xPtr = -1;
        } else {
            if(direction) {
                if(parent != nullptr) {
                    parent->applyExplosion(xPtr, nullptr, direction);
                }
            }
        }
    }
    if(yPtr != nullptr) {
        if(y == nullptr) {
            yVal += *yPtr;
            *yPtr = -1;
        } else {
            if(direction) {
                if(parent != nullptr) {
                    parent->applyExplosion(nullptr, yPtr, direction);
                } else if(*yPtr != -1) {
                    if(this->x != nullptr) {
                        this->x->applyExplosion(nullptr, yPtr, false);
                    }
                }
            } else {
                if(x != nullptr) {
                    x->applyExplosion(nullptr, yPtr, direction);
                } else {
                    xVal = *yPtr;
                    *yPtr = -1;
                }
                
            }
        }
    }
    return false;
}
}
