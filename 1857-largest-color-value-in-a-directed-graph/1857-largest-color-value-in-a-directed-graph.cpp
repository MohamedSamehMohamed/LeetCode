class Solution {
public:
    int vis[100002];
    vector<int> adj[100002];
    int dp[100002][26];
    bool cycle;
    string _colors;
    void dfs(int u){
        vis[u] = 1;
        for (int v: adj[u]){
            if (vis[v] == 1){
                cycle = 1;
                return;
            }
            if (!vis[v])
                dfs(v);
            for (int i = 0; i < 26; i++)
                dp[u][i] = max(dp[u][i], dp[v][i]);
        }
        vis[u] = 2;
        dp[u][_colors[u] - 'a']++;
    }
    
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        for (int i = 0; i < colors.size(); i++)
        {
            adj[i].clear();
            vis[i] = 0;
            for (int j = 0; j < 26; j++)
                dp[i][j] = 0;
        }
        cycle = 0;
        _colors = colors;
        for (int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
        }
        for (int i = 0; i < colors.size(); i++){
            if (vis[i] == 0){
                dfs(i);
            }
        }
        if (cycle) return -1;
        int mx = 1;
        for (int i = 0; i < colors.size(); i++) 
        {
            for (int j = 0; j < 26; j++)
                mx = max(mx, dp[i][j]);
        }
        
        
        return mx;
        
    }
};