class Solution {
public:
    int maxLikeTime[2][501];
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        maxLikeTime[0][0] = satisfaction[0];
        maxLikeTime[0][1] = -1e9;
        int mx = 0;
        int p = 1;
        for (int i = 1; i < n; i++){
            maxLikeTime[p][0] = max(satisfaction[i], maxLikeTime[p^1][0]);
            for (int k = 1; k <= i; k++){
                maxLikeTime[p][k] = maxLikeTime[p^1][k];
                maxLikeTime[p][k] = max(maxLikeTime[p][k], 
                                       maxLikeTime[p^1][k-1] + satisfaction[i] * (k+1));
            }
            maxLikeTime[p][i+1] = -1e9;
            p ^= 1;
        }
        for (int i = 0; i < n; i++)
            mx = max(mx, maxLikeTime[p^1][i]);
        return mx;
        
    }
};