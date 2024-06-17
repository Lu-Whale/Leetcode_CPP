//
// Created by 卢京宇 on 18/6/2024.
//

#include <cmath>

class _633_Sum_of_Square_Numbers {
public:
    bool judgeSquareSum(int c) {
        long left = 0;
        long right = static_cast<int>(sqrt(c));
        while (left <= right) {
            long sum = left * left + right * right;
            if(sum == c) {
                return true;
            }else if(sum > c) {
                right--;
            }else {
                left++;
            }
        }
        return false;
    }
};
