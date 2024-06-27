//
// Created by 卢京宇 on 27/6/2024.
//

#include <vector>
#include <unordered_map>
using namespace std;

class _1791_Find_Center_of_Star_Graph {
public:
    int findCenter(vector<vector<int>>& edges) {

        int u = edges[0][0], v = edges[0][1];
        int x = edges[1][0], y = edges[1][1];

        if (u == x || u == y) return u;
        return v;
    }
};