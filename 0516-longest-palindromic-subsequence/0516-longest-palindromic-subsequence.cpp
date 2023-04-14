class Solution {
public:
    int dp[1000][1000];
    int solve(string& s, int l, int r){
        if (l > r) return 0;
        if (l == r) return 1;
        int& ret = dp[l][r];
        if (~ret) return ret;
        ret = 0;
        ret = solve(s, l + 1, r - 1);
        if (s[l] == s[r]) ret = max(ret, 2 + solve(s, l + 1, r - 1));
        ret = max(ret, solve(s, l + 1, r));
        ret = max(ret, solve(s, l, r - 1));
        return ret;
    }
    int longestPalindromeSubseq(string s) {
        memset(dp, -1, sizeof dp);
        return solve(s, 0, s.size() - 1);
    }
};