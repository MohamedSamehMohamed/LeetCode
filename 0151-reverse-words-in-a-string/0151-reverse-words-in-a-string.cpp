class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int n = s.size();
        for (int i = 0; i < n; i++){
            if (s[i] == ' ') continue;
            string cur = "";
            cur += s[i];
            int j = i + 1;
            while (j < n && s[j] != ' ')cur += s[j++];
            words.push_back(cur);
            i = j - 1;
        }
        s = "";
        for (int i = words.size()-1; i >= 0; i--){
            s += words[i];
            if (i != 0) s += " ";
        }
        return s;
    }
};