class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0, n = mat.size();
        for (int i = 0; i < n; i++){
            sum += mat[i][i];
        }
        for (int r = 0, c = n-1; r < n; r++, c--){
            sum += mat[r][c];
        }
        return sum - (n&1? mat[n / 2][n / 2]: 0);
    }
};