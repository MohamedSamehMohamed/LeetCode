class Solution {
public:
    int msks[60], n;
    int dp[60][(1<<16)];
    int solve(int index, int rem){
        if (rem == 0)
            return 0;
        if (index == n)
            return n;
        int& ret = dp[index][rem];
        if (~ret) return ret;
        ret = solve(index + 1, rem);
        ret = min(ret, 1 + solve(index + 1, rem & ~(msks[index])));
        return ret;
    }
    vector<int> a;
    void build(int index, int rem){
        if (rem == 0 || index == n) return;
        int ret = dp[index][rem];
        if (ret == solve(index + 1, rem)){
            build(index + 1, rem);
            return;
        }
        a.push_back(index);
        build(index + 1, rem & ~(msks[index]));
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        a.clear();
        memset(dp, -1, sizeof dp);
        n = people.size();
        map<string, int> mp;
        for (auto i: req_skills)
        {
            int sz = mp.size();
            mp[i] = sz;
        }
        for (int i = 0; i < people.size(); i++){
            msks[i] = 0;
            for (int j = 0; j < people[i].size(); j++){
                msks[i]|=(1<<(mp[people[i][j]]));
            }
        }
        int bigMask = (1<<((int)mp.size())) - 1;
        solve(0, bigMask);
        build(0, bigMask);
        return a;
    }
};