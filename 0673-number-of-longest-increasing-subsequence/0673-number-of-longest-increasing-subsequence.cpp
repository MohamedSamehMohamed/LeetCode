class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxLen(n, 1);
        vector<long long> cnt(n, 1);
        int best = 1;
        for (int i = 1; i < n; i++){
            for (int j = 0; j < i; j++){
                if (nums[i] > nums[j] && maxLen[j] + 1 >= maxLen[i]){
                    if (maxLen[j] + 1 == maxLen[i]){
                        cnt[i] += cnt[j];    
                    }else {
                        cnt[i] = cnt[j];
                    }
                    maxLen[i] = maxLen[j] + 1;
                }
            }
            best = max(best, maxLen[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++){
            if (maxLen[i] == best){
                ans += cnt[i];
            }
        }
        return ans;
    }
};