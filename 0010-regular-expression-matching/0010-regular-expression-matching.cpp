class Solution {
public:
    int dp[21][21];
    int solve(string& s, string& p, int i, int j){
        while (j < p.size() && p[j] == '*') j++;
        if (i == s.size() && j == p.size()) return 1;
        if (j == p.size()) return 0;
        if (i == s.size()){
            int len = p.size() - j;
            if (len == 1 && p[j] == '*') return 1;
            if (len == 1) return 0;
            stack<char> stk;
            while (j < p.size()){
                if (p[j] == '*'){
                    if (stk.empty()) return 0;
                    stk.pop();
                }else {
                    stk.push(p[j]);
                }
                j++;
            }
            return stk.empty();
        }
        if (i > s.size() || j > p.size()) return 0;
        int& ret = dp[i][j];
        if (~ret) return ret;
        ret = 0;
        if (j + 1 < p.size() && p[j+1] == '*')
            ret = solve(s, p, i, j + 2);
        if (s[i] == p[j] || p[j] == '.')
        {
            ret |= solve(s, p, i + 1, j + 1);
            bool any = (p[j] == '.');
            if (j + 1 < p.size() && p[j+1] == '*'){
                int pos = 0;
                while (i  + pos < s.size() && (any || s[i+pos] == p[j])){
                    ret |= solve(s, p, i + pos + 1, j + 2);
                    pos++;
                }
                
            }
        }
        return ret;
        
    }
    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof dp);
        return solve(s, p, 0, 0);
    }
};