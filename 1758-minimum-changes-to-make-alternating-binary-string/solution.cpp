class Solution {
public:
    int minOperations(string s) {
        int startZeroCost = 0;
        int startOneCost = 0;
        for (int i = 0; i < s.size(); i++){
            if (i % 2 == 0){
                if (s[i] != '0') startZeroCost++;
                if (s[i] != '1') startOneCost++;
            }else {
                if (s[i] != '1') startZeroCost++;
                if (s[i] != '0') startOneCost++;
            }
        }
        return min(startZeroCost, startOneCost);
    }
};
