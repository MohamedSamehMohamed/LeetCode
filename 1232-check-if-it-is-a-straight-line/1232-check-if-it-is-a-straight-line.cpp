class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
     int a = coordinates[1][1] - coordinates[0][1];
     int b = coordinates[1][0] - coordinates[0][0];
     int g = __gcd(a, b);
     a /= g;
     b /= g;
     if (a <= 0 && b <= 0) a *= -1, b *= -1;
     if (a <= 0 || b <= 0){
         a = -1 * abs(a);
         b = abs(b);
     }
     for (int i = 2; i < coordinates.size(); i++){
         int curA = coordinates[i][1] - coordinates[0][1];
         int curB = coordinates[i][0] - coordinates[0][0];
         g = __gcd(curA, curB);
         curA /= g;
         curB /= g;
         if (curA <= 0 && curB <= 0) curA *= -1, curB *= -1;
         if (curA <= 0 || curB <= 0){
         curA = -1 * abs(curA);
         curB = abs(curB);
     }
     if (a != curA || b != curB)
         return 0;
     }
     return true;
    }
};