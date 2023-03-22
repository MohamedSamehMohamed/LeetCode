class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> frq;
        for (int i = 0; i < words.size(); i++)
            frq[words[i]]++;
        sort(words.begin(), words.end(),[&](string& a, string& b){
            if (frq[a] != frq[b])
                return frq[a] > frq[b];
            return a < b;
        });
        vector<string> topK;
        for (int i = 0; k && i < words.size(); ){
            topK.push_back(words[i]);
            i++;
            k--;
            while (i < words.size() && words[i] == words[i-1])
                i++;
        }
        return topK;
        
    }
};