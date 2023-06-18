class Solution {
public:
    int dp[1<<16][17];
    int Sum[1<<16];
    int sum;
    int getSum(vector<int>& nums, int msk){
        if (Sum[msk])
            return Sum[msk];
        int curMsk = 0;
        for (int i = nums.size()-1; i > -1; i--){
            if (msk & (1<<i))
            {
                curMsk |= (1<<i);
                Sum[msk] += nums[i];
                if (msk != curMsk)
                    Sum[curMsk] = Sum[msk];
            }
        }
        return Sum[msk];
    }
    int solve(vector<int>& nums, int rem, int msk){
        if (msk == 0)
            return rem == 0;
        if (rem == 0)
            return 0;
        int& ret = dp[msk][rem];
        if (~ret) return ret;
        ret = 0;
        for (int curMsk=msk;curMsk && !ret; curMsk=(curMsk-1)&msk) {
            if (getSum(nums, curMsk) == sum){
                ret = solve(nums, rem - 1, msk & (~curMsk));
            }
        }
        return ret;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        memset(dp, -1, sizeof dp);
        memset(Sum, 0, sizeof Sum);
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