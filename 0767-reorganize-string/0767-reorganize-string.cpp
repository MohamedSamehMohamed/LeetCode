class Solution {
public:
    string reorganizeString(string s) {
        vector<int> frq(26, 0);
        for (int i = 0; i < s.size(); i++){
            frq[s[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++){
            int rem = s.size() - frq[i];
            if (rem < frq[i] - 1)
                return "";
        }
        priority_queue<vector<int>> pq;
        for (int i = 0; i < 26; i++){
            if (frq[i]){
                pq.push({frq[i], i});
            }
        }
        s = "";
        while (pq.size()){
            int cur = pq.top()[1];
            pq.pop();
            s += char ('a' + cur);
            frq[cur]--;
            if (pq.size() == 0 && frq[cur] == 0)break;
            int sec = pq.top()[1];
            pq.pop();
            frq[sec]--;
            s += char('a' + sec);
            if (frq[cur])
                pq.push({frq[cur], cur});
            if (frq[sec])
                pq.push({frq[sec], sec});
        }
        return s;
    }
};