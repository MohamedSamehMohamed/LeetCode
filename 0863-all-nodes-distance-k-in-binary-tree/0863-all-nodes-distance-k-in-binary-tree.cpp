/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> adj[501];
    void init(){
        for (int i = 0; i < 501; i++)
            adj[i].clear();
    }
    void dfs(TreeNode* root, int par = -1){
        if (root == nullptr) return;
        if (~par){
            adj[par].push_back(root->val);
            adj[root->val].push_back(par);
        }
        if (root->left)
            dfs(root->left, root->val);
        if (root->right)
            dfs(root->right, root->val);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        init();
        dfs(root);
        vector<int> dist(501, -1);
        dist[target->val] = 0;
        queue<int> q;
        q.push(target->val);
        while (!q.empty()){
            int cur = q.front();
            q.pop();
            for (int v: adj[cur]){
                if (dist[v] == -1){
                    dist[v] = dist[cur] + 1;
                    q.push(v);
                }
            }
        }
        vector<int> ret;
        for (int i = 0; i < 501; i++)
            if (dist[i] == k)
                ret.push_back(i);
        return ret;
    }
};