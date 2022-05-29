class Solution {
public:
    int climbStairs(int n) {
        long long a = 1, b = 1 , c;
        if(n <= 1)
            return 1;
        
        for(int i = 2 ; i <= n;i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
        
    }
};