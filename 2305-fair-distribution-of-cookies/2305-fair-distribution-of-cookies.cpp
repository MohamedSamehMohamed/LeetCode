class Solution {
public:
    int mn, _k;
    int a[8];
    void solve(vector<int>& cookies, int index){
        if (index == cookies.size()){
            int mx = 0;
            for (int i = 0; i < _k; i++) 
                mx = max(mx, a[i]);
            mn = min(mn, mx);
            return;
        }
        for (int i = 0; i < _k; i++){
            a[i] += cookies[index];
            solve(cookies, index + 1);
            a[i] -= cookies[index];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        mn = 1e9;
        _k = k;
        memset(a, 0, sizeof a);
        solve(cookies, 0);
        return mn;
    }
};