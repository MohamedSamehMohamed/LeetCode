class Solution {
public:
    int mn;
    void solve(vector<int>& cookies, vector<int>& a, int index){
        if (index == cookies.size()){
            int mx = 0;
            for (int i = 0; i < a.size(); i++) mx = max(mx, a[i]);
            mn = min(mn, mx);
            return;
        }
        for (int i = 0; i < a.size(); i++){
            a[i] += cookies[index];
            solve(cookies, a, index + 1);
            a[i] -= cookies[index];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        mn = 1e9;
        vector<int> a(k, 0);
        solve(cookies, a, 0);
        return mn;
    }
};