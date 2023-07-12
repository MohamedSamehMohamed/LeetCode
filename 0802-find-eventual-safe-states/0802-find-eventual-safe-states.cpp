class Solution {
public:
    int vis[10009], bad[10009];
    stack<int> stk;
    void dfs(vector<vector<int>>& graph, int u){
        stk.push(u);
        vis[u] = 1;
        for (int v: graph[u]){
            if (vis[v] == 1){
                while (!stk.empty()){
                    int cur = stk.top();
                    stk.pop();
                    bad[cur] = 1;
                    if (cur == v) break;
                }
                bad[u] = 1;
                continue;
            }
            
            if (vis[v] == 2) {
                if (bad[v])
                    bad[u] = 1;
                continue;
            }
            dfs(graph, v);
            if (bad[v])
                bad[u] = 1;
        }
        if (stk.size())
            stk.pop();
        vis[u] = 2;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        memset(vis, 0, sizeof vis);
        memset(bad, 0, sizeof bad);
        for (int i = 0; i < graph.size(); i++){
            if (vis[i] == 0){
                dfs(graph, i);
            }
        }
        
        vector<int> ret;
        for (int i = 0; i < graph.size(); i++)
            if (!bad[i]) ret.push_back(i);
        return ret;
    }
};