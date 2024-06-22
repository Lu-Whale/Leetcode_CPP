//
// Created by 卢京宇 on 23/6/2024.
//
#include <iostream>
#include <vector>
using namespace std;

class _1248_Count_Number_of_Nice_Subarrays {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> odd;
        odd.push_back(-1);

        int ans = 0;
        int i = 1;
        for (int j = 0; j <= nums.size(); j++)
        {
            if (j == nums.size() || (nums[j] & 1))
            {
                odd.push_back(j);
            }

            if (odd.size() - i > k)
            {
                int left = odd[i] - odd[i - 1];
                int right = j - odd[odd.size() - 2];
                ans += left * right;
                i++;
            }
        }
        return ans;
    }
};
