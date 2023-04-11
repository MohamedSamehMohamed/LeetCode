class Solution {
public:
    int vis[100002];
    vector<int> adj[100002];
    map<int, vector<int>> mp;
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
        }
        vis[u] = 2;
    }
    vector<int> dfs2(int u){
        if (mp.find(u) != mp.end()) 
            return mp[u];
        vector<int> values(26, 0);
        
        
        for (int v: adj[u]){
            auto child = dfs2(v);
            for (int i = 0; i < 26; i++)
                values[i] = max(values[i], child[i]);
        }
        values[_colors[u] - 'a']++;
        return mp[u] = values;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        for (int i = 0; i < colors.size(); i++)
        {
            adj[i].clear();
            vis[i] = 0;
        }
        cycle = 0;
        mp.clear();
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
            dfs2(i);
        
        for (int i = 0; i < colors.size(); i++){
           for (int j = 0; j < 26; j++)
            {
               mx = max(mx, mp[i][j]);
            }
        }
        return mx;
        
    }
};