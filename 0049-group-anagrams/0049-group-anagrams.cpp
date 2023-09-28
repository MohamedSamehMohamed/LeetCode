class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<int,int>, vector<string>> mp;
        for (int i = 0; i < strs.size(); i++){
            map<int, int> cur;
            for (int j = 0; j < strs[i].size(); j++)
                cur[strs[i][j]]++;
            mp[cur].push_back(strs[i]);
        }
        vector<vector<string>> ret;
        for(auto it: mp)
            ret.push_back(it.second);
        return ret;
    }
};