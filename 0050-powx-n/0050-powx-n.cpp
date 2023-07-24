class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        bool flip = 0;
        long long N = n;
        if (n < 0) flip = 1, N = abs(n);
        while(N)
        {
            if (N % 2)
                res *= x;
            x *= x;
            N >>= 1;
        }
        if (flip) res = 1.0 / res;
        return res;
    }
};