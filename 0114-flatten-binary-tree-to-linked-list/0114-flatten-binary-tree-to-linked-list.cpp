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
    void flatten(TreeNode* root) {
        TreeNode* start = root;
        while (root){
            while (root->left == nullptr && root->right)
                root = root->right;
            if (root->left == nullptr && root->right == nullptr) break;
            if (root->left){
                TreeNode* largest = root->left;
                while (largest->right)
                    largest = largest->right;
                largest->right = root->right;
                
            }
            root->right = root->left;
            root->left = nullptr;
        }
        root = start;
    }
};