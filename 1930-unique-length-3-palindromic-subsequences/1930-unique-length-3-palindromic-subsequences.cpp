class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> prefix(26, 0), suffix(26, 0);
        for (int i = 0; i < s.size(); i++) 
            suffix[s[i] - 'a']++;
        int ans = 0;
        unordered_set<string> seen;
        for (int i = 0; i < s.size(); i++){
            suffix[s[i] - 'a']--;
            for (int j = 0; j < 26; j++){
                if (prefix[j] && suffix[j]){
                    string pal = string(1, char('a' + j)) + s[i];
                    if (seen.find(pal) == seen.end()){
                        ans++;
                        seen.insert(pal);
                    }
                }
            }
            prefix[s[i] - 'a']++;
        }
        return ans;
    }
};