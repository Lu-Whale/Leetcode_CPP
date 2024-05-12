//
// Created by 卢京宇 on 12/5/2024.
//
#include <vector>
#include <algorithm>
using namespace std;

class _2373_Largest_Local_Values_in_a_Matrix {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> res(n-2, vector<int>(n-2));

        for(int i = 0; i < n - 2; i++) {
            for(int j = 0; j < n - 2; j++) {
                res[i][j] = checkMax(grid, i, j);
            }
        }
        return res;
    }

    int checkMax(vector<vector<int>>& grid, int &i, int &j) {
        int Max = 0;
        for(int m = i; m < i+3; m++) {
            for(int n = j; n < j+3; n++) {
                Max = max(Max, grid[m][n]);
            }
        }
        return Max;
    }
};