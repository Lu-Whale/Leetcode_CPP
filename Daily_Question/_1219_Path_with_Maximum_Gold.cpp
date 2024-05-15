//
// Created by 卢京宇 on 15/5/2024.
//
#include <vector>
using namespace std;

class _1219_Path_with_Maximum_Gold {
public:
    int res, m, n, gold;
    vector<vector<bool>> visited;

    int getMaximumGold(vector<vector<int>>& grid) {
        res = 0;
        m = grid.size();
        n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] != 0) {
                    gold = 0;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& grid, int row, int column) {
        if(row < 0 || row >= m || column < 0 || column >= n) {
            return;
        }
        if(visited[row][column] || grid[row][column] == 0) {
            return;
        }

        visited[row][column] = true;
        gold += grid[row][column];
        res = max(res, gold);

        dfs(grid, row + 1, column);
        dfs(grid, row - 1, column);
        dfs(grid, row, column + 1);
        dfs(grid, row, column - 1);

        visited[row][column] = false;
        gold -= grid[row][column];
    }
};