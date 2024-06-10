//
// Created by 卢京宇 on 10/6/2024.
//
#include <vector>
using namespace std;

class _1051_Height_Checker {
public:
    int heightChecker(vector<int>& heights) {
        int res = 0;

        vector<int> expected = heights;
        sort(expected.begin(), expected.end());
        for(int i = 0; i < heights.size(); i++) {
            if(heights[i] != expected[i]) res++;
        }

        return res;
    }
};