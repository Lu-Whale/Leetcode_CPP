//
// Created by 卢京宇 on 26/6/2024.
//

#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class _1382_Balance_a_Binary_Search_Tree {
public:
    vector<TreeNode> vec;
    TreeNode* balanceBST(TreeNode* root) {
        inOrder(root);

        return dfs(0, vec.size() - 1);
    }

    void inOrder(TreeNode* root) {
        if(root == nullptr) return;

        inOrder(root->left);
        vec.emplace_back(* root);
        inOrder(root->right);
    }

    TreeNode* dfs(int left, int right) {
        if(left > right) return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(vec[mid]);
        root->left = dfs(left, mid - 1);
        root->right = dfs(mid + 1, right);
        return root;
    }
};