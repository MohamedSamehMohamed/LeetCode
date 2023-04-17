class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ret(candies.size(), 1);
        for (int i = 0; i < candies.size(); i++){
            candies[i] += extraCandies;
            for (int j = 0; j < candies.size(); j++){
                if (i == j) continue;
                if (candies[i] < candies[j])
                    ret[i] = 0;
            }
            candies[i] -= extraCandies;
        }
        return ret;
    }
};