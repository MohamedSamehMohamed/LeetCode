class Solution {
public:
    int ans;
    int score;
    int dp[1<<14];
    int solve(vector<int>& nums, int curMsk, int step){
        int n = nums.size();
        if (curMsk == (1<<n) - 1){
            return 0;
        }
        int& ret = dp[curMsk];
        if (~ret) return ret;
        
        for (int i = 0; i < n; i++){
            if (curMsk & (1<<i)) continue;
            for (int j = i + 1; j < n; j++){
                if (curMsk & (1<<j)) continue;
                int newMsk = curMsk | (1<<i) | (1<<j);
                ret = max(ret, step * __gcd(nums[i], nums[j]) + 
                solve(nums, newMsk, step + 1));
            }
        }
        return ret;
    }
    int maxScore(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        return solve(nums, 0, 1);
    }
};