//
//  Advent of Code 2021 Solutions: Day 21
//
//  https://adventofcode.com/2021
//
//  Created by vipermuffin on 12/21/2021.
//  Copyright © 2021 vipermuffin. All rights reserved.
//

#include "Day21.h"
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
#include <numeric> //std::accumulate
//#include <queue>
//#include <regex>
//#include <set>
//#include <sstream>
//#include <thread>
//#include <tuple>
//#include <unordered_map>
#include <unordered_map>


using namespace std;
namespace AocDay21 {

    static const std::string InputFileName = "Day21.txt";
//929625 too high
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        int playerIndex[2];
        sscanf(input[0].c_str(), "Player 1 starting position: %d",&playerIndex[0]);
        sscanf(input[1].c_str(), "Player 2 starting position: %d",&playerIndex[1]);

		return to_string(playGame(playerIndex[0], playerIndex[1]));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);

		return "---";
    }

int64_t playGame(int a, int b) {
    int playerIndex[] = {a,b};
    int playerScore[] = {0,0};
    int d{0};
    int i{0};
    while(playerScore[0]<1000 && playerScore[1]<1000) {
        playerIndex[i] += ++d;
        playerIndex[i] += ++d;
        playerIndex[i] += ++d;
        while(playerIndex[i]>10) {
            playerIndex[i] -= 10;
        }
        playerScore[i] += playerIndex[i];
        i++;
        i &= 1;
    }
    return playerScore[0] >= 1000 ? playerScore[1] * d: playerScore[0] * d;
}

std::pair<int64_t,int64_t> playGame2(const std::unordered_map<int64_t, int64_t>& pRolls, int a, int b, int aScore, int bScore, int turn, int64_t multiplier) {
    int playerIndex[] = {a,b};
    int playerScore[] = {aScore,bScore};
    int64_t playerWins[] = {0LL,0LL};
    int i = (turn+1)&1;
    
    for(const auto& roll : pRolls) {
        playerIndex[i] += roll.first;
        while(playerIndex[i] > 10) {
            playerIndex[i] -= 10;
        }
        playerScore[i] += playerIndex[i];
        if(playerScore[i] >= 21) {
            playerWins[i] += roll.second*multiplier;
        } else {
            auto result = playGame2(pRolls, playerIndex[0], playerIndex[1], playerScore[0], playerScore[1],i,roll.second*multiplier);
            playerWins[0] += result.first;
            playerWins[1] += result.second;
        }
        i++;
        i &= 1;
    }
    return make_pair(playerWins[0], playerWins[1]);
}
int64_t playGame2(int a, int b) {
    int playerIndex[] = {a,b};
    int playerScore[] = {0,0};
    int d{0};
    int i{0};
    //build possible combos
    std::vector<int> rolls{1,1,1,2,2,2,3,3,3};
    CombinationGenerator<int> rollCombos{rolls};
    auto possibleRolls = rollCombos.generateCombosChoose(3);
    unordered_map<int64_t,int64_t> pRolls{};
    for(const auto& roll : possibleRolls) {
        pRolls[std::accumulate(roll.begin(),roll.end(),0LL)]++;
    }
    
    auto result = playGame2(pRolls,a,b,0,0,1,1);
    cout << result.first << ' ' << result.second << endl;
    return result.first > result.second ? result.first : result.second;
}

}
