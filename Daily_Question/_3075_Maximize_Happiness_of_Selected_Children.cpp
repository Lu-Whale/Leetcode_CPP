//
// Created by 卢京宇 on 9/5/2024.
//
#include <vector>
#include <algorithm>
using namespace std;

class _3075_Maximize_Happiness_of_Selected_Children {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long res = 0;

        sort(happiness.begin(), happiness.end(), greater<int>());
        for(int i = 0; i < k; i++) {
            res += (happiness.at(i) - i) > 0 ? (happiness.at(i) - i) : 0;
        }

        return res;
    }
};