class Solution {
public:
    int par[300];
    int get_par(int u){
        return u == par[u]? u: par[u] = get_par(par[u]);
    }
    void uni(int u, int v){
        u = get_par(u);
        v = get_par(v);
        if (u != v)
            par[u] = v;
    }
    bool simi(string& a, string& b){
        int dif = 0;
        for (int i = 0; i < a.size(); i++){
            dif += (a[i] != b[i]);
        }
        return dif == 0 || dif == 2;
    }
    int numSimilarGroups(vector<string>& strs) {
        for (int i = 0; i < strs.size(); i++)
            par[i] = i;
        for (int i = 0; i < strs.size(); i++){
            for (int j = i + 1; j < strs.size(); j++){
                if (simi(strs[i], strs[j]))
                    uni(i, j);
            }
        }
        set<int> st;
        for (int i = 0; i < strs.size(); i++)
            st.insert(get_par(i));
        return st.size();
    }
};