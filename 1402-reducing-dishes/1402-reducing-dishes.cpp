class Solution {
public:
    int maxLikeTime[2][500];
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        maxLikeTime[0][0] = satisfaction[0];
        for (int i = 1; i < n; i++)
            maxLikeTime[0][i] = -1e9;
        int mx = 0;
        int p = 1;
        for (int i = 1; i < n; i++){
            maxLikeTime[p][0] = satisfaction[i];
            mx = max(maxLikeTime[p][0], mx);
            for (int k = 1; k < n; k++){
                maxLikeTime[p][k] = maxLikeTime[p^1][k];
                maxLikeTime[p][k] = max(maxLikeTime[p][k], 
                                       maxLikeTime[p^1][k-1] + satisfaction[i] * (k+1));
                mx = max(maxLikeTime[p][k], mx);
            }
            p ^= 1;
        }
        return mx;
        
    }
};