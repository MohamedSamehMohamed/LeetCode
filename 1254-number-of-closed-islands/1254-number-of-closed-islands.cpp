class Solution {
public:
    bool dfs(vector<vector<int>>& grid, int r, int c)
    {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size())
            return 0;
        if (grid[r][c] == 1)
            return 1;
        grid[r][c] = 1;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        int cur = 1;
        for (int i = 0; i < 4; i++)
        {
            int nr = dx[i] + r;
            int nc = dy[i] + c; 
            cur &= dfs(grid, nr, nc);
        }
        return cur;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int closedIslands = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 0)
                    closedIslands += dfs(grid, i, j);
            }
        return closedIslands;
    }
};