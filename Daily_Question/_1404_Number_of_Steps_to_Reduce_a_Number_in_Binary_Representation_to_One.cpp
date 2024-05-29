//
// Created by 卢京宇 on 30/5/2024.
//
#include <string>
using namespace std;


class _1404_Number_of_Steps_to_Reduce_a_Number_in_Binary_Representation_to_One {
public:
    int numSteps(string s) {
        int res = 0;
        while (s.size() > 1) {
            int i = s.size() - 1;
            if(s.at(i) == '0') {
                s.pop_back();
            }else {
                while (i >= 0 && s.at(i) == '1') {
                    s.at(i--) = '0';
                }
                if(i >= 0) {
                    s.at(i) = '1';
                }else {
                    s.insert(0, 1, '1');
                }
            }
            res++;
        }
        return res;
    }
};