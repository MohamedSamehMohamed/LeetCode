class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c)
    {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size())
            return -504*504;
        if (grid[r][c] == 0)
            return 0;
        grid[r][c] = 0;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        int cur = 1;
        for (int i = 0; i < 4; i++)
        {
            int nr = dx[i] + r;
            int nc = dy[i] + c; 
            cur += dfs(grid, nr, nc);
        }
        return cur;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int closedIslands = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    closedIslands += max(0, dfs(grid, i, j));
                }
            }
        return closedIslands;
    }
};