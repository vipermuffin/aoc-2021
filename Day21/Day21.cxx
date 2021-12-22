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
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <numeric> //std::accumulate
#include <unordered_map>


using namespace std;
namespace AocDay21 {

static const std::string InputFileName = "Day21.txt";

std::string solvea() {
    auto input = parseFileForLines(InputFileName);
    int playerIndex[2];
    (void)sscanf(input[0].c_str(), "Player 1 starting position: %d",&playerIndex[0]);
    (void)sscanf(input[1].c_str(), "Player 2 starting position: %d",&playerIndex[1]);
    
    return to_string(playGame(playerIndex[0], playerIndex[1]));
}

std::string solveb() {
    auto input = parseFileForLines(InputFileName);
    int playerIndex[2];
    (void)sscanf(input[0].c_str(), "Player 1 starting position: %d", &playerIndex[0]);
    (void)sscanf(input[1].c_str(), "Player 2 starting position: %d", &playerIndex[1]);
    
    return to_string(playGame2(playerIndex[0], playerIndex[1]));
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

std::pair<uint64_t,uint64_t> playGame2(const std::unordered_map<uint64_t, uint64_t>& pRolls, int a, int b, int aScore, int bScore, int turn) {
    uint64_t playerWins[] = {0ULL,0ULL};
    int i = (turn+1)&1;
    
    for(const auto& roll : pRolls) {
        int playerIndex[] = { a,b };
        int playerScore[] = { aScore,bScore };
        if (playerScore[0] < 21 && playerScore[1] < 21) {
            playerIndex[i] += static_cast<int>(roll.first);
            while (playerIndex[i] > 10) {
                playerIndex[i] -= 10;
            }
            playerScore[i] += playerIndex[i];
            if (playerScore[i] >= 21) {
                playerWins[i] += roll.second;
            }
            else {
                auto result = playGame2(pRolls, playerIndex[0], playerIndex[1], playerScore[0], playerScore[1], i);
                playerWins[0] += result.first * roll.second;
                playerWins[1] += result.second * roll.second;
            }
        }
    }
    return make_pair(playerWins[0], playerWins[1]);
}

uint64_t playGame2(int a, int b) {
    
    int d{0};
    int i{0};
    //build possible combos
    unordered_map<uint64_t, uint64_t> pRolls{};
    for (uint64_t i = 1; i < 4; i++) {
        for (uint64_t j = 1; j < 4; j++) {
            for (uint64_t z = 1; z < 4; z++) {
                pRolls[i + j + z]++;
            }
        }
    }
    
    auto result = playGame2(pRolls, a, b, 0, 0, 1);
    
    return result.first > result.second ? result.first : result.second;
}

}
