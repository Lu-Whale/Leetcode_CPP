//
// Created by 卢京宇 on 18/5/2024.
//
#include <vector>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class _979_Distribute_Coins_in_Binary_Tree {
int ans = 0;

    pair<int, int> dfs(TreeNode *node) {
        if (node == nullptr)
            return {0, 0};
         // 递归处理左子树和右子树
        auto coins_l_nodes_l = dfs(node->left); // 使用一个临时变量来接收返回值
        int coins_l = coins_l_nodes_l.first;
        int nodes_l = coins_l_nodes_l.second;

        auto coins_r_nodes_r = dfs(node->right); // 使用一个临时变量来接收返回值
        int coins_r = coins_r_nodes_r.first;
        int nodes_r = coins_r_nodes_r.second;

        int coins = coins_l + coins_r + node->val; // 子树硬币个数
        int nodes = nodes_l + nodes_r + 1; // 子树节点数
        ans += abs(coins - nodes);
        return {coins, nodes};
    }

public:
    int distributeCoins(TreeNode *root) {
        dfs(root);
        return ans;
    }
};