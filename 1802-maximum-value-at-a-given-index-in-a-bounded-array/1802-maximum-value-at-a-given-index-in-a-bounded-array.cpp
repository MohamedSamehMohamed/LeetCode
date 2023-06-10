class Solution {
public:
    long long sumTo(int n){
        return (1LL * n * (n+1)) >> 1LL;
    }
    long long sumRange(int from, int to){
        // from, from + 1, from + 2, ..., to 
        return sumTo(to) - sumTo(from - 1);
     }
    int maxValue(int n, int index, int maxSum) {
        int l = 1, r = maxSum, m, ans = 1;
        while (l <= r){
            m = (l+r) >> 1;
            long long sum = m;
            int segment[] = {index, n - index-1};
            for (int i = 0; i < 2; i++){
                if (m-1 >= segment[i]){
                    sum += sumRange(m-1-segment[i]+1,m-1);
                }else {
                    sum += sumTo(m-1);
                    sum += segment[i] - m + 1;
                }
            }
            if (sum <= maxSum){
                ans = m;
                l = m + 1;
            }else {
                r = m - 1;
            }
        }
        return ans;
    }
};