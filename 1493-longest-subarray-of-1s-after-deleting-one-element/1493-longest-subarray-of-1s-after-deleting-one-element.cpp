class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, 0), suf(n, 0);
        pre[0] = nums[0];
        suf[n-1] = nums[n-1];
        for (int i = 1; i < n; i++)
            pre[i] = (nums[i]? pre[i-1] + 1: 0);
        for (int i = n-2; i >= 0; i--)
            suf[i] = (nums[i]? suf[i+1] + 1: 0);
        int ans = 0;
        for (int i = 0; i < n; i++){
            int mxPre = (i-1>=0? pre[i-1]: 0);
            int mxSuf = (i+1 < n? suf[i+1]: 0);
            ans = max(ans, mxPre + mxSuf);
        }
        return ans;
    }
};