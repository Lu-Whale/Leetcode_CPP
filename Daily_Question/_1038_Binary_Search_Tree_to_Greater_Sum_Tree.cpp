
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

class _1038_Binary_Search_Tree_to_Greater_Sum_Tree {
public:
    int sum = 0;

    TreeNode* bstToGst(TreeNode* root) {
        inOrderSum(root);
        inOrderPlus(root);

        return root;
    }

    void inOrderSum(TreeNode* root) {
        if(root == nullptr) return;

        inOrderSum(root->left);
        sum += root->val;
        inOrderSum(root->right);
    }

    void inOrderPlus(TreeNode* root) {
        if(root == nullptr) return;

        inOrderPlus(root->left);
        sum -= root->val;
        root->val += sum;
        inOrderPlus(root->right);
    }

};