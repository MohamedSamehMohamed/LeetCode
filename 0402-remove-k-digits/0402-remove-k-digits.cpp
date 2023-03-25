class Solution {
public:
    string removeKdigits(string num, int k) {
        
        vector<vector<int>> indeces(10);
        
        stack<char> stk;
        stk.push(num[0]);
        for (int i = 1; i < num.size(); i++){
            while (k && !stk.empty() && num[i] < stk.top()){
                stk.pop();
                k--;
            }
            stk.push(num[i]);
        }
        string ret = "";
        while (!stk.empty()){
            ret += stk.top();
            stk.pop();
        }
        while (ret.size() > 0 && ret.back() == '0') 
            ret.pop_back();
        reverse(ret.begin(), ret.end());
        num = ret;
        for (int i = 0; i < num.size(); i++) indeces[num[i] - '0'].push_back(i);
        for (int d = 9; d >= 0 && k; d--){
            for (int j: indeces[d]){
                if (k == 0) break;
                k--;
                num[j] = '#';
            }
        }
        ret = "";
        for (int i = 0; i < num.size(); i++) 
        {
            if (num[i] != '#')
                ret += num[i];
        }
        if (ret.size() == 0) ret += "0";
        return ret;
    }
};