//
// Created by 卢京宇 on 9/6/2024.
//
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m = {{0,-1}};
        int rem = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            rem = (rem + nums[i])%k;
            if(m.count(rem))
            {
                int pos = m[rem];
                if((i - pos) >= 2)
                    return true;
            }
            else
                m[rem] = i;
        }
        return false;
    }
};
