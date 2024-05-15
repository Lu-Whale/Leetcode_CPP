//
// Created by 卢京宇 on 15/5/2024.
//
#include <numeric>
#include <vector>
#include <queue>
using namespace std;

class _2812_Find_the_Safest_Path_in_a_Grid {
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int maximumSafenessFactor(vector<vector<int>> &grid) {
        int n = grid.size();
        vector<pair<int, int>> q;
        vector<vector<int>> dis(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    q.emplace_back(i, j);
                    dis[i][j] = 0;
                }
            }
        }

        vector<vector<pair<int, int>>> groups = {q};
        while (!q.empty()) { // 多源 BFS
            vector<pair<int, int>> nq;
            for (auto &[i, j]: q) {
                for (auto &d: dirs) {
                    int x = i + d[0], y = j + d[1];
                    if (0 <= x && x < n && 0 <= y && y < n && dis[x][y] < 0) {
                        nq.emplace_back(x, y);
                        dis[x][y] = groups.size();
                    }
                }
            }
            groups.push_back(nq); // 相同 dis 分组记录
            q = move(nq);
        }

        // 并查集模板
        vector<int> fa(n * n);
        iota(fa.begin(), fa.end(), 0);
        function<int(int)> find = [&](int x) -> int { return fa[x] == x ? x : fa[x] = find(fa[x]); };

        for (int ans = (int) groups.size() - 2; ans > 0; ans--) {
            for (auto &[i, j]: groups[ans]) {
                for (auto &d: dirs) {
                    int x = i + d[0], y = j + d[1];
                    if (0 <= x && x < n && 0 <= y && y < n && dis[x][y] >= dis[i][j])
                        fa[find(x * n + y)] = find(i * n + j);
                }
            }
            if (find(0) == find(n * n - 1)) // 写这里判断更快些
                return ans;
        }
        return 0;
    }
};
