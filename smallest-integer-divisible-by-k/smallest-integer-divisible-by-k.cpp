class Solution {
public:
    int smallestRepunitDivByK(int k) {
        long long temp = 0;
        for( int i = 0 ; i <= k ;i++)
        {
            temp = (temp * 10 + 1) % k;
            if(temp % k == 0)
                return (i+1);
        }
        return -1;
        
    }
};