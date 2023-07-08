/*
when k = 1, a[n] + a[1]

when k = 2 
let i be the split point 
1, 2, 3, 4, ..., i
i+1, i+2, ..., n
a[n] + a[1] + a[i+1] + a[i]

*/
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<int> sumConsective;
        for (int i = 1; i < weights.size(); i++){
            sumConsective.push_back(weights[i] + weights[i-1]);
        }
        sort(sumConsective.begin(), sumConsective.end());
        long long mx = 0, mn = 0;
        mx =  mn = weights.back() + weights[0];
        for (int i = 0; i < k-1; i++){
            mn += sumConsective[i];
            mx += sumConsective[ sumConsective.size()-1-i ];
        }
        return mx - mn;
    }
};