class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0, n = nums.size(), mod = 1e9 + 7;
        vector<int> pow2(n+1, 0);
        pow2[0] = 1;
        for (int i = 1; i <= n; i++)
            pow2[i] = (pow2[i-1] << 1) % mod;
        for (int i = 0; i < n; i++){
            int l = i, r = n-1, m, upper = -1;
            while (l <= r){
                m = (l+r) >> 1;
                if (nums[m] + nums[i] <= target)
                    upper = m, l = m + 1;
                else 
                    r = m - 1;
            }
            if (upper == -1) continue;
            int len = upper - i;
            ans = (ans + pow2[len] % mod) % mod;
        }
        
        return ans;
            
            
    }
};