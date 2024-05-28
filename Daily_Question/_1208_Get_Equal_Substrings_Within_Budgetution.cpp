//
// Created by 卢京宇 on 28/5/2024.
//
#include <vector>
#include <string>
#include <cmath>
using namespace std;


class _1208_Get_Equal_Substrings_Within_Budgetution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size(), res = 0;
        vector<int> costs(n);
        for(int i = 0; i < n; i++) {
            costs[i] = abs(s.at(i) - t.at(i));
        }

        int left = 0, currCost = 0;
        for(int right = 0; right < n; right++) {
            currCost += costs[right];
            while (left <= right && currCost > maxCost) {
                currCost -= costs[left++];
            }
            res = max(res, right - left + 1);
        }

        return res;
    }
};