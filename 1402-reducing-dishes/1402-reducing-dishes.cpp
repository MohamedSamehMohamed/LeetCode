class Solution {
public:
    int dp[501][501];
    int solve(vector<int>& a, int tk, int idx)
    {
        if (idx == a.size()) return 0;
        int& ret = dp[tk][idx];
        if (~ret) return ret;
        return ret = max(solve(a, tk, idx + 1), tk * a[idx] + solve(a, tk + 1, idx + 1));
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        memset(dp, -1, sizeof dp);
        return solve(satisfaction, 1, 0);
    }
};