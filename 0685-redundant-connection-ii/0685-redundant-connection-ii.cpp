class Solution {
public:
    vector<int> par, deg;
    int get_par(int u){
        return u == par[u]? u: par[u] = get_par(par[u]);
    }
    void unit(int u, int v){
        u = get_par(u);
        v = get_par(v);
        if (u == v) return;
        par[u] = v;
    }
    bool same(int u, int v){
        return get_par(u) == get_par(v);
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        par.clear();
        deg.clear();
        int n = edges.size();
        for (int i = 0; i < n; i++)
        {
            par.push_back(i);
            deg.push_back(0);
        }
        int two_par = -1;
        for (int i = 0; i < edges.size(); i++){
            int v = edges[i][1] - 1;
            deg[v]++;
            if (deg[v] > 1)
                two_par = v;
        }
        int index = -1;
        if (two_par == -1){
            for (int i = 0; i < edges.size(); i++){
                int u = edges[i][0], v = edges[i][1];
                u--;v--;
                if (same(u, v))
                {
                    index = i;
                }
                else 
                    unit(u, v);
            }
        }else {
            vector<int> indeces;
            for (int i = 0; i < edges.size(); i++){
                if (edges[i][1]-1 == two_par){
                    indeces.push_back(i);
                }
            }
            swap(indeces[0], indeces[1]);
            // answer is one of indeces 
            for (int id: indeces){
                for (int i = 0; i < n; i++)
                {
                    par[i] = i;
                }
                int edgeCnt = 0;
                for (int i = 0; i < edges.size(); i++){
                    int u = edges[i][0], v = edges[i][1];
                    u--;v--;
                    if (i == id) continue;
                    if (!same(u, v))
                    {
                        unit(u, v);
                        edgeCnt++;
                    }
                }
                if (edgeCnt == n-1){
                    if (index == -1) index = id;
                    index = max(index, id);
                }else {
                    index = indeces[1];
                }
                break;
            }
        }
        return edges[index];
    }
};