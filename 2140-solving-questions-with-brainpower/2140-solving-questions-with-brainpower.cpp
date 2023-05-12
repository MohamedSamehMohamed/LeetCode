class Solution {
public:
    long long dp[100009];
    long long solve(vector<vector<int>>& q, int i){
        if (i >= q.size()) return 0;
        long long& ret = dp[i];
        if (~ret) return ret;
        ret = max(solve(q, i + 1), 
                 q[i][0] + solve(q, i + q[i][1] + 1));
        return ret;
    }
    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp, -1, sizeof dp);
        return solve(questions, 0);
    }
};