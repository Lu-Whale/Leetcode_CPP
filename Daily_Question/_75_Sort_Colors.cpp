//
// Created by 卢京宇 on 12/6/2024.
//

#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class _75_Sort_Colors {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count(3);
        for(int num : nums) {
            count[num]++;
        }

        int i = 0;
        while (i < nums.size()) {
            while (count[0]-- > 0) nums[i++] = 0;
            while (count[1]-- > 0) nums[i++] = 1;
            while (count[2]-- > 0) nums[i++] = 2;
        }
    }

};