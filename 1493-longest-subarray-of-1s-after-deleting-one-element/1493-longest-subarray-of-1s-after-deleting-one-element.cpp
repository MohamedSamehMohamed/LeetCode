class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeroCount = 0, l = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++){
            zeroCount += !nums[i];
            while (zeroCount > 1)
                zeroCount -= !nums[l++];
            ans = max(ans, i - l);
        }
        return ans;
    }
};