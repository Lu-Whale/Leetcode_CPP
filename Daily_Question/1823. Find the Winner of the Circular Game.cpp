//
// Created by 卢京宇 on 2024/7/8.
//
#include <vector>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> arr;
        for(int i = 1; i <= n; i++) {
            arr.push_back(i);
        }
        int index = 0;

        while (arr.size() > 1) {
            int nextToErase = (index + k - 1) % arr.size();
            arr.erase(arr.begin() + nextToErase);
            index = nextToErase;
        }

        return arr[0];
    }
};