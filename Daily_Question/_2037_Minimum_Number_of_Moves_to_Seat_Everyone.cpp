//
// Created by 卢京宇 on 13/6/2024.
//
#include <vector>
using namespace std;


class _2037_Minimum_Number_of_Moves_to_Seat_Everyone {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int res = 0, n = seats.size();

        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        for(int i = 0; i < n; i++) {
            res += abs(students[i] - seats[i]);
            students[i] = seats[i];
        }
        return res;
    }
};


// 3 6
// 1 4