class Solution {
public:
  int par[100009];
  int get_par(int u){
    return u == par[u]? u: par[u] = get_par(par[u]);
  }
  bool uni(int u, int v){
    u = get_par(u);
    v = get_par(v);
    if (u == v) return 0;
    par[u] = v;
    return 1;
  }
  vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList,
          vector<vector<int>>& queries) {
    for (int i = 0; i < n; i++){
      par[i] = i;
    }
    sort(edgeList.begin(), edgeList.end(), [](vector<int>&a, vector<int>&b){
      return a[2] < b[2];
    });
    for (int i = 0; i < queries.size(); i++){
        queries[i].push_back(i);
    }
    sort(queries.begin(), queries.end(), [](vector<int>&a, vector<int>&b){
      return a[2] < b[2];
    });
    int j = 0;
    vector<bool> ret(queries.size());
    for (int i = 0; i < queries.size(); i++){
      while (j < edgeList.size() && edgeList[j][2] < queries[i][2]){
        uni(edgeList[j][0], edgeList[j][1]);
        j++;
      }
      if (get_par(queries[i][0]) == get_par(queries[i][1]))
        ret[queries[i][3]] = 1;
      else 
        ret[queries[i][3]] = 0;
    }
    return ret;
  }
};