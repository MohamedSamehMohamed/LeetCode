class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        int l = 1, r = (n + m) * 1000, h;
        vector<vector<int>> cost(n);
        for (int i = 0; i < n; i++){
            cost[i] = vector<int>(m, 0);
        }
        int dx[] = {1, 0};
        int dy[] = {0, 1};
        while (l <= r){
            int mid = (l+r) >> 1;
            priority_queue<vector<int>> q;
            q.push({mid + dungeon[0][0], 0, 0});
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    cost[i][j] = 0;
            cost[0][0] = mid + dungeon[0][0];
            if (cost[0][0] <= 0)
                q.pop();
            while (!q.empty()){
                auto cur = q.top();
                q.pop();
                if (cur[1] == n-1 && cur[2] == m - 1) break;
                for (int i = 0; i < 2; i++){
                    int nr = dx[i] + cur[1];
                    int nc = dy[i] + cur[2];
                    if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                    if (cur[0] + dungeon[nr][nc] <= 0 ||
                        cost[nr][nc] >= cur[0] + dungeon[nr][nc]) continue;
                    cost[nr][nc] = cur[0] + dungeon[nr][nc];
                    q.push({cur[0] + dungeon[nr][nc], nr, nc});
                }
            }
            if (cost[n-1][m-1] > 0)
                h = mid, r = mid - 1;
            else 
                l = mid + 1;
        }
        return h;
    }
};