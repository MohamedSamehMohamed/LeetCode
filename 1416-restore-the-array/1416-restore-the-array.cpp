class Solution {
public:
    int mod = 1e9 + 7;
    int dp[100009];
    int solve(string& s, int k, int index){
        if (index == s.size()) return 1;
        int& ret = dp[index];
        if (~ret) return ret;
        ret = 0;
        if (s[index] == '0') return 0;
        long long cur = 0;
        for (int i = index; i < s.size(); i++){
            cur = cur * 10 + (s[i] -'0');
            if (cur > k) break;
            if (i + 1 < s.size() && s[i + 1] == '0') continue;
            ret = (ret + solve(s, k, i + 1) % mod) % mod;
        }
        return ret;
    }
    int numberOfArrays(string s, int k) {
        memset(dp, -1, sizeof dp);
        return solve(s, k, 0);
    }
};