class Solution {
public:
    int dp[1<<16][17];
    int sum;
    int solve(vector<int>& nums, int rem, int msk){
        if (msk == 0)
            return rem == 0;
        if (rem == 0)
            return 0;
        int& ret = dp[msk][rem];
        if (~ret) return ret;
        ret = 0;
        for (int curMsk=msk;curMsk && !ret; curMsk=(curMsk-1)&msk) {
            int curSum = 0;
            for (int i = 0; i < nums.size(); i++){
                if (curMsk & (1<<i))
                    curSum += nums[i];
            }
            if (curSum == sum){
                ret = solve(nums, rem - 1, msk & (~curMsk));
            }
        }
        return ret;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        memset(dp, -1, sizeof dp);
        sum = 0;
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        if (sum % k)
            return 0;
        sum /= k;
        int n = nums.size();
        return solve(nums, k, (1<<n)-1);
    }
};