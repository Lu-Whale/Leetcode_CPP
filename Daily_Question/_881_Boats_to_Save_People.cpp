#include <string>
#include <vector>
#include <iostream>
using namespace std;

class _881_Boats_to_Save_People {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int res = 0;

        sort(people.begin(), people.end());

        int l = 0, r = people.size() - 1;
        while (l < r) {
            while (l < r && people[l] + people[r] > limit) {
                res++;
                r--;
            }

            res++;
            l++;
            r--;
        }

        return l == r ? res + 1 : res;
    }
};
