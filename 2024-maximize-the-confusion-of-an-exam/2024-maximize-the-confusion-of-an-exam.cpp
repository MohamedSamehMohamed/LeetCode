class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
       int ans = k;
       int l = 0, r = 0, n = answerKey.size();
       int cntT = 0, cntF = 0;
       while (r < n){
           while (r < n && 
           min(cntF + (answerKey[r] == 'F'), cntT + (answerKey[r] == 'T')) <= k){
            cntF += answerKey[r] == 'F';
            cntT += answerKey[r] == 'T';
            r++;
           }
           ans = max(ans, r - l);
           cntF -= answerKey[l] == 'F';
           cntT -= answerKey[l] == 'T';
           l++;
       } 
       return ans;
    }
};
/*
"TFFT"
1
*/