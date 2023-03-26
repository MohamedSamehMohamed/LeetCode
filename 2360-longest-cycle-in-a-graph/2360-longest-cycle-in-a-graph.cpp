class Solution {
public:
    int vis[100000];
    vector<int> adj[100000];
    int cycleLen;
    stack<int> path;
    void dfs(int u){
        vis[u] = 1;
        path.push(u);
        for (int v: adj[u]){
            if (vis[v] == 1){
                int curLen = 1;
                while (path.top() != v){
                    path.pop();
                    curLen++;
                }
                cycleLen = max(curLen, cycleLen);
                continue;
            }
            if (vis[v] == 0)
                dfs(v);
        }
        vis[u] = 2;
    }
    int longestCycle(vector<int>& edges) {
        for (int i = 0; i < edges.size(); i++){
            vis[i] = 0;
            adj[i].clear();
        }
        for (int i = 0; i < edges.size(); i++){
            if (~edges[i]){
                adj[i].push_back(edges[i]);
            }
        }
        cycleLen = -1;
        for (int i = 0; i < edges.size(); i++){
            if (vis[i] == 0){
                dfs(i);
            }
        }
        return cycleLen;
    }
};