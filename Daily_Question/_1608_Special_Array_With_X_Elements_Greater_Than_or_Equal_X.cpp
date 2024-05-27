//
// Created by 卢京宇 on 28/5/2024.
//
#include <vector>
#include <algorithm>
using namespace std;


class _1608_Special_Array_With_X_Elements_Greater_Than_or_Equal_X {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int i = 0; i <= nums.size(); i++) {
            if(i == binarySearch(nums, i)) {
                return i;
            }
        }

        return -1;
    }

    int binarySearch(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] < k) {
                left = mid + 1;
            }else {
                right = mid;
            }
        }

        if(left < nums.size() && nums[left] >= k) {
            return nums.size() - left;
        }else {
            return -1;
        }
    }
};