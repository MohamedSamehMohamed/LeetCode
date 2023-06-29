class Solution {
public:
    int vis[30][30][1<<6];
    int countBits(int msk){
        int cnt = 0;
        for (int i = 0; i < 6; i++){
            cnt += ((1<<i) & msk) > 0;
        }
        return cnt;
    }
    int shortestPathAllKeys(vector<string>& grid) {
        memset(vis, -1, sizeof vis);
        queue<vector<int>> q;
        int row = grid.size();
        int col = grid[0].size();
        int numOfKeys = 0;
        int startR = 0, startC = 0;
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if (grid[i][j] >= 'a' && grid[i][j] <= 'z')
                    numOfKeys++;
                if (grid[i][j] == '@'){
                    startR = i;
                    startC = j;
                }
            }
        }
        q.push({startR, startC, 0});
        vis[startR][startC][0] = 1;
        int moves = 0;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        while (!q.empty()){
            int curSize = q.size();
            while (curSize--){
                auto cur = q.front();
                q.pop();
                if (countBits(cur[2]) == numOfKeys)
                    return moves;
                int curMask = cur[2];
                for (int i = 0; i < 4; i++){
                    int newRow = cur[0] + dx[i];
                    int newCol = cur[1] + dy[i];
                    int newMsk = curMask;
                    if (newRow < 0 || newCol < 0 || newRow >= row || newCol >= col)
                        continue;
                    if (grid[newRow][newCol] == '#')
                        continue;
                    if (grid[newRow][newCol] >= 'A' && grid[newRow][newCol] <= 'Z'){
                        int pos = grid[newRow][newCol] - 'A';
                       
                        if (!(curMask & (1<<pos)))
                            continue;
                    }
                    if (grid[newRow][newCol] >= 'a' && grid[newRow][newCol] <= 'z'){
                       int pos = grid[newRow][newCol] - 'a'; 
                       newMsk |= (1<<pos);
                    }
                    if (vis[newRow][newCol][curMask] != -1)
                            continue;
                    vis[newRow][newCol][newMsk] = 1;
                    q.push({newRow, newCol, newMsk});
                }
                }
            
            moves++;
        }
        return -1;
    }
};