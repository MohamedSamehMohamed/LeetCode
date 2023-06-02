class Solution {
public:
    bool intersect(int px1, int py1, int r, int px2, int py2){
        // if distance between the centers is lessthan or equal to r 
        return 1LL * (px1 - px2) * (px1 - px2) + 1LL * (py1 - py2) * (py1 - py2) <= 1LL * r * r;
    }
    vector<int> adj[101];
    int vis[101];
    void dfs(int node){
        if (vis[node]) return;
        vis[node] = 1;
        for (int v: adj[node]){
            dfs(v);
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        for (int i = 0; i < n; i++)
            adj[i].clear();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (i == j) continue;
                if (intersect(bombs[i][0], bombs[i][1], bombs[i][2], 
                              bombs[j][0], bombs[j][1]))
                adj[i].push_back(j);
            }
        }
        int ans = 0;
        for(int node = 0; node < n; node++){
            memset(vis, 0, sizeof vis);
            dfs(node);
            int current = 0;
            for (int i = 0; i < n; i++){
                current += vis[i];
            }
            ans = max(ans, current);
        } 
        return ans;
    }
};