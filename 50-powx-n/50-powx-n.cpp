class Solution {
public:
    double myPow(double x, int n1) {
        
        double ans = 1.0;
        int flag = 0;
        long long n = n1;
        if(n < 0)
            flag = 1;
        n = abs(n);
        while(n > 0)
        {
            if(n & 1)
            {
                ans *= x;
                n--;
            }
            else
            {
                x *= x;
                n /= 2;
            }
        }
        if(flag)
        {
            ans = (double)1 / (double)ans;
        }
        return ans;
    }
};