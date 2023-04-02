class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans(spells.size());
        vector<int> ord(spells.size());
        for (int i = 0; i < ord.size(); i++) ord[i] = i;
        sort(ord.begin(), ord.end(), [&](int i, int j){return spells[i] < spells[j];});
        int j = potions.size() - 1;
        for (int i = 0; i < ord.size(); i++){
            while (j >= 0 && 1LL * spells[ord[i]] * potions[j] >= success)
                j--;
            ans[ord[i]] = potions.size() - j - 1;
        }
        return ans;
    }
};