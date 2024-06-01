//
// Created by 卢京宇 on 1/6/2024.
//

#include <vector>
using namespace std;

class _3110_Score_of_a_String {
public:
    int scoreOfString(string s) {
        int res = 0;
        for(int i = 0; i < s.size() - 1; i++) {
            res += abs(s.at(i) - s.at(i+1));
        }
        return res;
    }
};
