//
// Created by 卢京宇 on 17/5/2024.
//
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class _1325_Delete_Leaves_With_a_Given_Value {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        const bool flag = dfs(root, target);
        return flag ? nullptr : root;
    }

    bool dfs(TreeNode* root, int target) {
        if(root->left) {
            if(dfs(root->left, target)) {
                root->left = nullptr;
            }
        }
        if(root->right) {
            if(dfs(root->right, target)) {
                root->right = nullptr;
            }
        }

        if(root->left == nullptr && root->right == nullptr && root->val == target) {
            return true;
        }
        return false;
    }

};