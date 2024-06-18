//
// Created by 卢京宇 on 18/6/2024.
//
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class _826_Most_Profit_Assigning_Work {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size(), m = worker.size();
        sort(worker.begin(), worker.end());
        vector<pair<int, int>> jobs(n);
        for(int i = 0; i < n; i++) {
            jobs[i] = {difficulty[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.first < b.first;
        });
        int res = 0, j = 0, max_profit = 0;

        for (int w : worker) {
            while (j < n && jobs[j].first <= w) {
                max_profit = max(max_profit, jobs[j++].second);
            }
            res += max_profit;
        }

        return res;
    }
};