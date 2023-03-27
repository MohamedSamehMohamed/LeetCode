class Solution {
public:
    int X  =0 , Y = 0  ; 
    int dp[1001][1001]; 
    int ans (vector<vector<int>>& grid , int x , int y )
    {
        if (x < 0 || y < 0 || x >= X || y >= Y )return 1e8 ; 
        if (x == X-1 && y == Y - 1  )return grid[x][y]; 
        int &ret = dp[x][y]; 
        if (ret != -1 )return ret ; 
        return ret = grid[x][y] + min (ans(grid,x+1,y) , ans (grid,x,y+1)); 
        
    }
    int minPathSum(vector<vector<int>>& grid) {
    memset (dp , -1 ,sizeof dp ); 
    X = grid.size(); 
    if (X)
    Y = grid[0].size();
    
    return ans (grid,0,0); 
    }
};