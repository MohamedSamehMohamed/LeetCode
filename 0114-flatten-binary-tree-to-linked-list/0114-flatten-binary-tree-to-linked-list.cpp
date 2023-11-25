/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* tail = nullptr;
    void flattenTree(TreeNode* root){
        if (root == nullptr) return;
        tail = root;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left = nullptr;
        root->right = left;
        flattenTree(root->right);
        if (tail != nullptr)
            tail->right = right;
        flattenTree(right);
    }
    void flatten(TreeNode* root) {
        flattenTree(root);
    }
};