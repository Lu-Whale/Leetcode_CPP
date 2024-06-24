//
// Created by 卢京宇 on 25/6/2024.
//
#include <vector>
#include <queue>
using namespace std;

// https://leetcode.cn/problems/minimum-number-of-k-consecutive-bit-flips/solutions/607694/hua-dong-chuang-kou-shi-ben-ti-zui-rong-z403l/
class _995_Minimum_Number_of_K_Consecutive_Bit_Flips {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int N = nums.size();
        queue<int> que;
        int res = 0;
        for (int i = 0; i < N; ++i) {
            if (!que.empty() && i >= que.front() + k) {
                que.pop();
            }
            if (que.size() % 2 == nums[i]) {
                if (i + k > N) {
                    return -1;
                }
                que.push(i);
                res ++;
            }
        }
        return res;
    }
};