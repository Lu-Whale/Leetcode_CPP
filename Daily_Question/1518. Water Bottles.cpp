//
// Created by 卢京宇 on 2024/7/8.
//
#include <iostream>
using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = 0, empty = 0;
        while (numBottles + empty >= numExchange) {
            res += numBottles;
            int tempEmpty = (numBottles + empty) % numExchange;
            numBottles = (numBottles + empty) / numExchange;
            empty = tempEmpty;
        }
        res += numBottles;
        return res;
    }
};