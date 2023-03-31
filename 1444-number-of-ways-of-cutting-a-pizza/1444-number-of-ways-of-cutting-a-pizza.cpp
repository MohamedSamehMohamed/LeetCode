class Solution {
public:
    
    map<vector<int>, int> dp;
    int sum[50][50];
    bool contain_apple(int upLeftRow, int upLeftCol, int downRightRow, int downRightCol){
        int total = sum[downRightRow][downRightCol];
        if (upLeftRow-1 >= 0) total -= sum[upLeftRow-1][downRightCol];
        if (upLeftCol-1 >= 0) total -= sum[downRightRow][upLeftCol-1];
        if (upLeftRow-1>=0&&upLeftCol-1>=0) total += sum[upLeftRow-1][upLeftCol-1];
        return total > 0;
    }
    int mod = 1e9 + 7;
    int solve(vector<string>& p, int leftRow, int leftCol, int rightRow, int rightCol, int rem){
        if (rem == 1) return contain_apple(leftRow, leftCol, rightRow, rightCol);
        if (dp.find({leftRow, leftCol, rightRow, rightCol, rem}) != dp.end())
            return dp[{leftRow, leftCol, rightRow, rightCol, rem}];
        int& ret = dp[{leftRow, leftCol, rightRow, rightCol, rem}];
        ret = 0;
        for (int c = leftCol; c < rightCol; c++){
            if (contain_apple(leftRow, leftCol, rightRow, c)){
                ret = (ret + solve(p, leftRow, c+1, rightRow, rightCol, rem - 1) % mod) % mod;
            }
        }
        for (int r = leftRow; r < rightRow; r++){
            if (contain_apple(leftRow, leftCol, r, rightCol)){
                ret = (ret + solve(p, r + 1, leftCol, rightRow, rightCol, rem - 1) % mod) % mod;
            }
        }
        return ret;
    }
    int ways(vector<string>& pizza, int k) {
        int n = pizza.size(), m = pizza[0].size();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                sum[i][j] = (pizza[i][j] == 'A');
                if (i) sum[i][j] += sum[i-1][j];
                if (j) sum[i][j] += sum[i][j-1];
                if (i && j) sum[i][j] -= sum[i-1][j-1];
            }
        }
        dp = map<vector<int>, int>();
        return solve(pizza, 0, 0, n-1, m-1, k);
    }
};