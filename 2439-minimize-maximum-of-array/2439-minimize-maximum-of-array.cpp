class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int l = 0, r = 1e9, m, ans = 1e9;
        auto can = [&](int tar){
            long long unUsed = 0;
            for (int i = 0; i < nums.size(); i++){
                int cur = nums[i];
                if (cur > tar){
                    if (cur - tar > unUsed) return 0;
                    unUsed -= cur - tar;
                    cur = tar;
              }
              unUsed += tar - cur;
            }  
            return 1;
        };
        while (l <= r){
            m = (l+r) >> 1;
            if (can(m)){
                ans = m;
                r = m - 1;
            }else {
                l = m + 1;
            }
        }
        return ans;
    }
};