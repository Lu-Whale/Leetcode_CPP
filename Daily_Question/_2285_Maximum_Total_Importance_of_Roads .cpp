//
// Created by 卢京宇 on 30/6/2024.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class _2285_Maximum_Total_Importance_of_Roads {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long res = 0;

        vector<int> values(n, 0);
        for(vector<int> road : roads) {
            values[road[0]]++;
            values[road[1]]++;
        }
        //node, edges
        vector<pair<int, int>> nodes;
        for(int i = 0; i < n; i++) {
            nodes.emplace_back(i, values[i]);
        }

        sort(nodes.begin(), nodes.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.second < b.second;
        });

        unordered_map<int ,int> map;
        for(int i = 0; i < n; i++) {
            map[nodes[i].first] = i + 1;
        }

        for(vector<int> road : roads) {
            res += (map[road[0]] + map[road[1]]);
        }

        return res;
    }

    long long maximumImportance_optimized(int n, std::vector<std::vector<int>>& roads) {
        long long res = 0;

        // 创建一个包含节点索引和连接数的向量
        std::vector<std::pair<int, int>> nodes(n);
        for (int i = 0; i < n; ++i) {
            nodes[i].first = i;
        }

        // 计算每个节点的连接数
        for (const auto& road : roads) {
            nodes[road[0]].second++;
            nodes[road[1]].second++;
        }

        // 按连接数排序节点
        std::sort(nodes.begin(), nodes.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.second < b.second;
        });

        // 直接计算最终的重要性值
        for (int i = 0; i < n; ++i) {
            // 将节点的新重要性分数赋值给原位置，即 i + 1 为新重要性分数
            nodes[i].second = i + 1;
        }

        // 计算所有道路的重要性总和
        for (const auto& road : roads) {
            res += nodes[road[0]].second + nodes[road[1]].second;
        }

        return res;
    }
};

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> node(n, 0);
        for(auto &v : roads){
            node[v[0]]++;
            node[v[1]]++;
        }
        sort(node.begin(), node.end());
        long long ans = 0;
        for(int i = 0; i < n; i++){
            ans += 1LL * node[i] * (i+1);
        }
        return ans;
    }
};
