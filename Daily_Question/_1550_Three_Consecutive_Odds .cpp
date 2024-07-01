//
// Created by 卢京宇 on 2/7/2024.
//

#include <vector>
using namespace std;

class _1550_Three_Consecutive_Odds {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] % 2 == 1) {
                count++;
                if(count >= 3) return true;
            }else {
                count = 0;
            }
        }
        return false;
    }
};