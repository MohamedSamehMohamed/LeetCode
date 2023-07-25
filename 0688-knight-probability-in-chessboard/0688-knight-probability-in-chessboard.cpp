class Solution {
public:
    double dp[25][25][101];
    double solve(int row, int column, int rem, int n){
        if (rem == 0) return 1.0;
        double& ret = dp[row][column][rem];
        if (ret == ret) return ret;
        ret = 0;
        int pass = 0;
        for(int i = -2; i <= 2; i++){
            for (int j = -2; j <= 2; j++){
                if (abs(i) == abs(j) || i == 0 || j == 0) continue;
                int nrow = row + i;
                int ncol = column + j;
                if (nrow < 0 || ncol < 0 || nrow >= n || ncol >= n) {
                    continue;
                }
                ret += solve(nrow, ncol, rem - 1, n) / 8;
            }
        }
        return ret;
    }
    double knightProbability(int n, int k, int row, int column) {
        memset(dp, -1, sizeof dp);
        return solve(row, column, k, n);
    }
};