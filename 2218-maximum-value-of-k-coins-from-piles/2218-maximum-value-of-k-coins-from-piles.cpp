class Solution {
public:
    int dp[1000][2001];
    int solve(vector<vector<int>>& p, int i, int rem){
        if (rem == 0) return 0;
        if (i == p.size()) return -1e9;
        int& ret = dp[i][rem];
        if (~ret) return ret;
        ret = solve(p, i + 1, rem);
        int sum = 0;
        for (int j = 0; rem - j - 1 >= 0 && j < p[i].size(); j++){
            sum += p[i][j];
            ret = max(ret, sum + solve(p, i + 1, rem - j - 1));
        }
        return ret;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp, -1, sizeof dp);
        return solve(piles, 0, k);
    }
};