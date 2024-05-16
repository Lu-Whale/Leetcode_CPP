//
// Created by 卢京宇 on 16/5/2024.
//

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if(root->val == 0 || root->val == 1) {
            return root->val;
        }

        const bool left = evaluateTree(root->left);
        const bool right = evaluateTree(root->right);
        return root->val == 2 ? left || right : left && right;
    }
};