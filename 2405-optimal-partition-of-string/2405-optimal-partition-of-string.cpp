class Solution {
public:
    int partitionString(string s) {
        int cnt = 0;
        for (int i = 0; i < s.size();){
            vector<int> frq(26, 0);
            cnt++;
            while (i < s.size() && frq[s[i] - 'a'] == 0){
                frq[s[i] - 'a']++;
                i++;
            }
        }
        return cnt;
    }
};