class Solution {
public:
    void simplify(int& a, int& b){
        int g = __gcd(a, b);
        a /= g;
        b /= g;
        if (a <= 0 && b <= 0){
            a *= -1;
            b *= -1;
        }
        if (a <= 0 || b <= 0){
            a = -1 * abs(a);
            b = abs(b);
        }
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
     int a = coordinates[1][1] - coordinates[0][1];
     int b = coordinates[1][0] - coordinates[0][0];
     simplify(a, b);
     for (int i = 2; i < coordinates.size(); i++){
         int curA = coordinates[i][1] - coordinates[0][1];
         int curB = coordinates[i][0] - coordinates[0][0];
         simplify(curA, curB);
         if (a != curA || b != curB)
            return 0;
         }
     return true;
    }
};