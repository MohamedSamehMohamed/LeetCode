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
    // easy solution 
    vector<int> v;
    void dfs(TreeNode* root){
        if (root == nullptr) return;
        v.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    int dfs2(TreeNode* root, int extra = 0){
        if (root == nullptr) return 0;
        int left = dfs2(root->left, extra);
        root->val = v[left + extra];
        int right = dfs2(root->right, extra + left + 1);
        return left + right + 1;
    }
    void recoverTree(TreeNode* root) {
        v.clear();
        dfs(root);
        sort(v.begin(), v.end());
        dfs2(root);
    }
};