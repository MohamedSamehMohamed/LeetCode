class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        for (int i = 0; i < nums.size(); ){
            string cur = to_string(nums[i]);
            i++;
            while (i < nums.size() && 1LL * nums[i] - nums[i-1] == 1){
                i++;
            }
            if (to_string(nums[i-1]) != cur)
                cur += "->" + to_string(nums[i-1]);
            ret.push_back(cur);
        }
        return ret;
    }
};