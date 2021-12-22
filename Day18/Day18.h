//
//  Advent of Code 2021 Solutions: Day 18
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/18/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

namespace AocDay18 {
//Function Definitions
class SnailfishNumber {
public:
    SnailfishNumber();
    SnailfishNumber(const std::string&, SnailfishNumber* p = nullptr);
    SnailfishNumber(const int x, const int y, SnailfishNumber* p = nullptr);
    SnailfishNumber(const SnailfishNumber&, SnailfishNumber* p = nullptr);
    ~SnailfishNumber();
    void operator+=(SnailfishNumber& rhs);
    void reduce();
    int magnitude() const;
    std::string toString() const;
private:
    bool explode(int level, int* xPtr, int* yPtr);
    bool applyExplosion(int *xPtr, int* yPtr, bool direction);
    SnailfishNumber* parent;
    SnailfishNumber* x;
    SnailfishNumber* y;
    int xVal;
    int yVal;
};

}
