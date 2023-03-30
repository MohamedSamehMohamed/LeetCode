class Solution {
public:
    int dp[30][30][30];
    int solve(string& a, string& b, int l, int r, int l1, int r1){
        bool same = 1;
        for (int i = l; i <= r; i++){
            if (a[i] != b[l1+(i-l)]){
                same = 0;
                break;
            }
        }
        if (same || l == r) return same;
        int& ret = dp[l][r][l1];
        if (~ret) return ret;
        ret = 0;
        for (int i = 1; ret == 0 && i < (r-l+1); i++){
            ret |= (solve(a, b, l, l + i - 1, l1, l1 + i - 1) && solve(a, b, l + i, r, l1 + i, r1));
            ret |= (ret || (solve(a, b, l+i, r, l1, l1 + (r-(l+i)+1) - 1) && solve(a, b, l, l+i-1, l1 + (r-(l+i)+1), r1)));
        }
        return ret;
    }
    bool isScramble(string s1, string s2) {
        memset(dp, -1 ,sizeof dp);
        return solve(s1, s2, 0, s1.size()-1, 0, s2.size()-1);
    }
};