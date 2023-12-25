class Solution {
public:
    int numDecodings(string s) {
        vector<int> ways(s.size());
        ways[0] = (s[0] != '0');
        for (int i = 1; i < s.size(); i++){
            // can be added to the previous digit 
            // dd -> 1x -> x {0:9}
            // dd -> 2x -> x {0:6}
            bool canBeAdded = 0;
            if (s[i-1] == '1'){
                canBeAdded = (s[i] >= '0' && s[i] <= '9');
            }else if (s[i-1] == '2'){
                canBeAdded = (s[i] >= '0' && s[i] <= '6');
            }
            // can be single 
            bool canBeSingle = 0;
            if (s[i] != '0')
                canBeSingle = true;
            
            ways[i] = ways[i-1] * canBeSingle + 
                    (i-2>=0? ways[i-2]: s[i-1]!='0'? 1: 0) * canBeAdded;
        }
        return ways[s.size()-1];
    }
};

class Solution_Recursive {
public:
    int dp[101];
    int solve(string& s, int i = 0)
    {
        if (i == s.size())
            return 1;
        int &ret = dp[i];
        if (~ret) return ret;
        if (s[i] == '0') return ret = 0;
        ret = solve(s, i + 1);
        if ( i + 1 < s.size() && (s[i] - '0') * 10 + (s[i+1] - '0') <= 26)
            ret += solve(s, i + 2);
        return ret;
    }
    int numDecodings(string s) {
     memset(dp, -1, sizeof dp);
     return solve(s);
    }
};
