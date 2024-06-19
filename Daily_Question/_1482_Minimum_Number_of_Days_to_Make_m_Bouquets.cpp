//
// Created by 卢京宇 on 20/6/2024.
//
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class _1482_Minimum_Number_of_Days_to_Make_m_Bouquets {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int res = -1, n = bloomDay.size();
        if(m > n / k) return res;
        int left = 0x7FFFFFFF, right = -1;

        for(int i = 0; i < n; i++) {
            left = min(left, bloomDay[i]);
            right = max(right, bloomDay[i]);
        }

        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 0, temp = 0;
            for(int i = 0; i < n; i++) {
                if(mid >= bloomDay[i]) {
                    temp++;
                    if(temp == k) {
                        count++;
                        temp = 0;
                    }
                }else {
                    temp = 0;
                }
            }
            if(count < m) {
                left = mid + 1;
            }else {
                right = mid;
            }
        }
        return left;
    }
};