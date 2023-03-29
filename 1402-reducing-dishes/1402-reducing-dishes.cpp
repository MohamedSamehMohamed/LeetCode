class Solution {
public:
    int maxLikeTime[500][500];
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        maxLikeTime[0][0] = satisfaction[0];
        for (int i = 1; i < n; i++)
            maxLikeTime[0][i] = -1e9;
        int mx = 0;
        for (int i = 1; i < n; i++){
            maxLikeTime[i][0] = satisfaction[i];
            mx = max(maxLikeTime[i][0], mx);
            for (int k = 1; k < n; k++){
                maxLikeTime[i][k] = maxLikeTime[i-1][k];
                maxLikeTime[i][k] = max(maxLikeTime[i][k], 
                                       maxLikeTime[i-1][k-1] + satisfaction[i] * (k+1));
                mx = max(maxLikeTime[i][k], mx);
            }
        }
        return mx;
        
    }
};