//
// Created by 卢京宇 on 9/6/2024.
//
#include <unordered_map>
#include <vector>
using namespace std;

class _974_Subarray_Sums_Divisible_by_K {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;

        vector<int> prefix(n + 1);
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum = (nums[i] + sum) % k;
            if(sum < 0) sum += k;
            prefix[i + 1] = sum;
        }

        unordered_map<int, int> m = {{0, 1}};
        for(int i = 1; i < n + 1; i++) {
            if(m.count(prefix[i])) {
                res += m[prefix[i]];
            }
            m[prefix[i]] += 1;
        }

        return res;
    }
};