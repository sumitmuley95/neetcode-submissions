class Solution {
public:
    double myPow(double x, int n) {
        double ans = x;
        if(n == 0) return 1;
        if(n == 1) return x;
        int m = abs(n)-1;

        while(m) {
            ans = ans*x;
            m--;
        }
        if(n < 0) return 1/ans;
        return ans;
    }
};
