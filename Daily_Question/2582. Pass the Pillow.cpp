//
// Created by 卢京宇 on 2024/7/7.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int passThePillow(int n, int time) {
        int group = (2 * n - 2);
        int index = time % group;
        if(index < n) {
            return index + 1;
        }else {
            index %= n;
            return n - index - 1;
        }
    }
};