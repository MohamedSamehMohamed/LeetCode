class Solution {
public:
    bool vis[1001];
    void dfs(int node, vector<vector<int>>& rooms){
        vis[node] = 1;
        for (int i = 0; i < rooms[node].size(); i++){
            if (vis[rooms[node][i]] == 0){
                dfs(rooms[node][i], rooms);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        memset(vis, 0, sizeof vis);
        dfs(0, rooms);
        for (int i = 0; i < rooms.size(); i++){
            if (!vis[i])
                return 0;
        }
        return 1;
    }
};