class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<int> masks;
        for (int i = 0; i + k <= s.size(); i++){
            int msk = 0;
            for (int j = i; j < i + k; j++){
                if (s[j] == '1') 
                    msk |= (1<<(j-i));
            }
            masks.insert(msk);
            if (masks.size() == (1<<k)) break;
        }
        return masks.size() == (1<<k);
    }
};