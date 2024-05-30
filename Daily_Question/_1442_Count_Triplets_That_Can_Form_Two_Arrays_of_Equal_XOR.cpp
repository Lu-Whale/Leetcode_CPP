//
// Created by 卢京宇 on 31/5/2024.
//
#include <vector>
using namespace std;

class _1442_Count_Triplets_That_Can_Form_Two_Arrays_of_Equal_XOR {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size(), res = 0;
        vector<int> prefix(n);
        int prev = 0;
        for(int i = 0; i < n; i++) {
            prefix.at(i) = arr.at(i) ^ prev;
            prev = prefix.at(i);
        }

        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                if((prefix[i] ^ arr[i]) == prefix[j]) {
                    res += (j - i);
                }
            }
        }

        return res;
    }
};