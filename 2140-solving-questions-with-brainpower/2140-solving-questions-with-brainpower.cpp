class Solution {
public:
    long long dp[100009];
    
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        dp[n-1] = questions[n-1][0];
        for (int i = n - 2; i >= 0; i--){
            int pos = i + questions[i][1] + 1;
            long long profit = (pos < n? dp[pos]: 0);
            dp[i] = max(dp[i+1], questions[i][0] + profit);
        }
        return dp[0];
    }
};