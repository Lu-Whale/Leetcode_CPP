//
// Created by 卢京宇 on 14/5/2024.
//
#include <vector>
using namespace std;

class _861_Score_After_Flipping_Matrix {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++) {
            if(grid[i][0] == 0) {
                for(int j = 0; j < n; j++) {
                    grid[i][j] = grid[i][j] == 0 ? 1 : 0;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < m; j++) {
                count += grid[j][i];
            }
            if(count * 2 < m) {
                for(int j = 0; j < m; j++) {
                    grid[j][i] = grid[j][i] == 0 ? 1 : 0;
                }
            }
        }

        int res = 0;
        for(int i = 0; i < m; i++) {
            int num = 0;
            for(int j = 0; j < n; j++) {
                num = num * 2 + grid[i][j];
            }
            res += num;
        }
        return res;
    }
};