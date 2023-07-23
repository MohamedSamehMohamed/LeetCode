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
    map<int, vector<TreeNode*>> mp; 
    vector<TreeNode*> gen(int rem)
    {
        if (rem % 2 == 0) 
        {
            return vector<TreeNode*>();
        }
        if (rem == 1)
        {
            TreeNode* cur = new TreeNode(0);
            vector<TreeNode*> ret;
            ret.push_back(cur);
            return ret;
        }
        if (mp.find(rem) != mp.end()) return mp[rem];
        vector<TreeNode*> ret;
        for (int i = 0; i < rem; i++)
        {
            vector<TreeNode*> left = gen(i);
            vector<TreeNode*> right = gen(rem - i - 1);
            for (int j = 0; j < left.size(); j++)
                for (int k = 0; k < right.size(); k++)
                {
                    TreeNode* cur = new TreeNode(0);
                    cur->left = left[j];
                    cur->right = right[k];
                    ret.push_back(cur);
                }
        }
        mp[rem] = ret;
        return ret;
        
        
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        return gen(n);
    }
};