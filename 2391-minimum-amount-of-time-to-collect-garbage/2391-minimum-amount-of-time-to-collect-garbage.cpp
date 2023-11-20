class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int g_last = -1, p_last = -1, m_last = -1;
        int n = garbage.size();
        int ans = 0;
        for (int i = 0; i < n; i++){
            ans += garbage[i].size();
            for (int j = 0; j < garbage[i].size(); j++){
                if (garbage[i][j] == 'M')
                    m_last = i - 1;
                if (garbage[i][j] == 'P')
                    p_last = i - 1;
                if (garbage[i][j] == 'G')
                    g_last = i - 1;
            }
        }
        for (int i = 0; i < n; i++){
            if (m_last >= i)
                ans += travel[i];
            if (p_last >= i)
                ans += travel[i];
            if (g_last >= i)
                ans += travel[i];
        }
        return ans;
    }
};