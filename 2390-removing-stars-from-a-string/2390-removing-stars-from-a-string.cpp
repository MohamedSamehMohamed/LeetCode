class Solution {
public:
    string removeStars(string s) {
        stack<char> stk;
        stk.push(s[0]);
        for (int i = 1; i < s.size(); i++){
            if (s[i] == '*')
                stk.pop();
            else 
                stk.push(s[i]);
        }
        s = "";
        while (stk.empty() == 0){
            s += stk.top();
            stk.pop();
        }
        reverse(s.begin(), s.end());
        return s;
    }
};