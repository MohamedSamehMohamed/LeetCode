class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> avgs;
        long long kBefore = 0, kAfter = 0;
        for (int i = 0; i < nums.size(); i++){
            int avg = -1;
            if (i - k >= 0 && i + k < nums.size()){
                avg = (kBefore + kAfter + nums[i]) / (2*k+1);
                kBefore -= nums[i-k];
                kAfter -= (i+1 < nums.size()?nums[i+1]:0);
            }else {
                
            }
            kBefore += nums[i];
            kAfter += (i+k+1 < nums.size()? nums[i+k+1]: 0);
            avgs.push_back(avg);
        }
        return avgs;
    }
};