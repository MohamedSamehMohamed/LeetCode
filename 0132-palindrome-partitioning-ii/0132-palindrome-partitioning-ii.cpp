class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> nxt(n);
        for (int i = 0; i < n; i++){
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]){
                nxt[l].push_back(r);
                l--;r++;
            }
            l = i-1, r = i;
            while (l >= 0 && r < n && s[l] == s[r]){
                nxt[l].push_back(r);
                l--;r++;
            }
        }
        int inf = 2 * n;
        vector<int> minCutVec(n+1, inf);
        minCutVec[n] = 0;
        for (int i = n-1; i >= 0; i--){
            for (int j: nxt[i]){
                minCutVec[i] = min(minCutVec[i], minCutVec[j+1] + 1);
            }
        }
        return minCutVec[0] - 1;
    }
};