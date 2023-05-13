class Solution {
public:
    
    int dp[100009];
    int L, R, Z, O, mod = 1e9 + 7;
    int solve(int i){
        if (i > R) return 0;
        int& ret = dp[i];
        if(~ret) return ret;
        ret = ((i >= L) + solve(i + Z)%mod) % mod;
        ret = (ret + solve(i + O) % mod) % mod;
        return ret;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp, -1, sizeof dp);
        L = low, R = high, Z = zero, O = one;
        return solve(0);
    }
};