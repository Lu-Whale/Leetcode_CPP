//
// Created by 卢京宇 on 4/7/2024.
//

#include <vector>
#include <limits>
using namespace std;

class _1509_Minimum_Difference_Between_Largest_and_Smallest_Value_in_Three_Moves {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) {
            return 0;
        }

        vector<int> maxn(4, -1e9), minn(4, 1e9);
        for (int i = 0; i < n; i++) {
            int add = 0;
            while (add < 4 && maxn[add] > nums[i]) {
                add++;
            }
            if (add < 4) {
                for (int j = 3; j > add; j--) {
                    maxn[j] = maxn[j - 1];
                }
                maxn[add] = nums[i];
            }
            add = 0;
            while (add < 4 && minn[add] < nums[i]) {
                add++;
            }
            if (add < 4) {
                for (int j = 3; j > add; j--) {
                    minn[j] = minn[j - 1];
                }
                minn[add] = nums[i];
            }
        }
        int res = 2e9;
        for (int i = 0; i < 4; i++) {
            res = min(res, maxn[i] - minn[3 - i]);
        }
        return res;
    }
};