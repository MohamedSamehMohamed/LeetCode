class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        map<int, int> mp;
        int mx = 0;
        mp[arr.back()] = 0;
        for (int i = arr.size() - 2; i >= 0; i--){
            int next = arr[i] + difference;
            if (mp.count(next)){
                mp[arr[i]] = max(mp[arr[i]], mp[next] + 1);
            }else 
                mp[arr[i]] = 0;
            mx = max(mx, mp[arr[i]] + 1);
        }
        return mx;
    }
};