class Solution {
public:
    int divide(int dividend, int divisor) {
        int dividend_sign = 1 , divisor_sign = 1;
        long long dividendd = dividend;
        long long divisorr = divisor;
        long long int ans = (dividendd / divisorr);
        
        if(divisor == 0 or dividend == 0)
            return 0;
        if(dividendd < 0)
        {
            dividend_sign = -1 ;
            dividendd *= -1;
        }
        if(divisor < 0)
        {
            divisor_sign = -1;
            divisorr *= -1;
        }
        
        return ans > INT_MAX ? INT_MAX : ans;
    }
};