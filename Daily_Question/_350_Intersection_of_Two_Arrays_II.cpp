//
// Created by 卢京宇 on 2/7/2024.
//

#include <vector>
#include <unordered_map>
using namespace std;

class _350_Intersection_of_Two_Arrays_II {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        for(int num : nums1) {
            if(map.count(num)) {
                map[num]++;
            }else {
                map[num] = 1;
            }
        }

        vector<int> res;
        for(int num : nums2) {
            if(map.count(num) && map[num] > 0) {
                res.emplace_back(num);
                map[num]--;
            }
        }

        return res;
    }
};