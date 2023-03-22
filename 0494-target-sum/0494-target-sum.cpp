class Solution {
public:
    int ways = 0;
    void countWays(vector<int>&nums, int index, int curSum, int target){
        if (index == nums.size()){
            if (curSum == target){
                ways++;
            }
            return;
        }
        countWays(nums, index + 1, curSum + nums[index], target);
        countWays(nums, index + 1, curSum - nums[index], target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        ways = 0;
        countWays(nums, 0, 0, target);
        return ways;
    }
};