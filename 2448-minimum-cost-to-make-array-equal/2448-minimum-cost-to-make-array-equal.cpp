class Solution {
public:
    void addRange(vector<long long>& a, vector<long long>& rate, 
                  int st, int en, long long startValue, int valueChange){
        if (st > en) return;
        a[st] += startValue;
        rate[st+1] += valueChange;
        a[en+1] -= startValue + 1LL * (en-st) * valueChange;
        rate[en+1] -= valueChange;
    }
    void complete(vector<long long>& a, vector<long long>& rate){
        long long totalChange = 0;
        int len = 1e6;
        for (int i = 2; i <= len; i++){
            totalChange += rate[i];
            a[i] += a[i-1];
            a[i] += totalChange;
        }
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int len = 1e6 + 3;
        vector<long long> a(len, 0), rate(len, 0);
        for (int i = 0; i < nums.size(); i++){
            int val = nums[i];
            addRange(a, rate, val + 1, len - 3, 1LL * cost[i], cost[i]);
            addRange(a, rate, 1, val - 1, 1LL * cost[i] * (val-1), -cost[i]);
        }
        complete(a, rate);
        long long best = 1e18;
        for (int i = 1; i <= len - 3; i++){
               best = min(best, a[i]);
        }
        return best;
    }
};