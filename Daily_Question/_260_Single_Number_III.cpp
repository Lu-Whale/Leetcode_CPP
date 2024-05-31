//
// Created by 卢京宇 on 31/5/2024.
//
#include <vector>
using namespace std;

class _260_Single_Number_III {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res(2);

        unsigned int allXOR = 0;
        for(int num : nums) {
            allXOR ^= num;
        }
        int flag = allXOR & -allXOR;
        for(int num : nums) {
            if((flag & num) == 0) {
                res[0] ^= num;
            }else {
                res[1] ^= num;
            }
        }
        return res;
    }
};

class Solution_260 {
public:
    vector<int> singleNumber(vector<int> &nums) {
        unsigned int xor_all = 0;
        for (int x: nums) {
            xor_all ^= x;
        }
        int lowbit = xor_all & -xor_all;
        vector<int> ans(2);
        for (int x: nums) {
            ans[(x & lowbit) != 0] ^= x; // 分组异或
        }
        return ans;
    }
};