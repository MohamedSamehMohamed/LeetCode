class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, sum = 0, n = nums.size();
        int len = n+1;
        while (l < n){
            while (r < n && sum < target){
                sum += nums[r++];
            }
            if (sum >= target){
                len = min(len, r - l);
            }
            sum -= nums[l++];
        }
        if (len == n+1) len = 0;
        return len;
    }
};