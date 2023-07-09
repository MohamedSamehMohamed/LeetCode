class Solution {
public:
    int largestVariance(string s) {
        int variance = 0;
        for (int i = 0; i < 26; i++){
           for (int j = 0; j < 26; j++){
               int larCount = 0, smallCount = 0, smallCountRem = 0;
               for (int k = 0; k < s.size(); k++)
                   smallCountRem += s[k] == j + 'a';
               
               for (int k = 0; k < s.size(); k++){
                   if (s[k] == i + 'a') larCount++;
                   else if (s[k] == j + 'a') smallCount++, smallCountRem--;
                   if (smallCount > 0){
                       variance = max(variance, larCount - smallCount);
                   }
                   if (larCount < smallCount && smallCountRem > 0){
                       larCount = smallCount = 0;
                   }
               }
           }
        }
        return variance;
    }
};