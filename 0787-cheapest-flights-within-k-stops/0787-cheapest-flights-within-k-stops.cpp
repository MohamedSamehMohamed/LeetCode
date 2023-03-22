class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<vector<int>> pq;
        pq.push({0, 0, src});
        vector<vector<int>> dist(n), adj[n];
        for (int i = 0; i < flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        int inf = 1e9;
        for (int i = 0; i < n; i++)
            dist[i] = vector<int>(k+2, inf);
        for (int i = 0; i <= k+1; i++)
            dist[src][i] = 0;
        while (!pq.empty())
        {
            auto cur = pq.top();
            cur[0] *= -1;
            cur[1] *= -1;
            pq.pop();
            if (cur[1] > k) continue;
            for (auto v: adj[cur[2]]){
                if (dist[cur[2]][cur[1]] + v[1] < dist[v[0]][1+cur[1]]){
                    dist[v[0]][1+cur[1]] = dist[cur[2]][cur[1]] + v[1];
                    pq.push({-dist[v[0]][1+cur[1]], -1-cur[1], v[0]});
                }
            }
        }
        int mn = inf;
        for (int i = 0; i <= k+1; i++)
            mn = min(mn, dist[dst][i]);
        if (mn == inf) mn = -1;
        return mn;
    }
};