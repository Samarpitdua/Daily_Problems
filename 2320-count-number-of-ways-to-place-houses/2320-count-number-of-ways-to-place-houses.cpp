#define mod 1000000007
class Solution {
public:
    int countHousePlacements(int n) {
        long long a = 1 , b = 2 , c;
        if(n == 1)
            return 4;
        for(int i = 2 ; i <=n ;i++)
        {
            c = a + b;
            c = c % mod;
            a = b;
            b = c;
            a %= mod;
            b %= mod;
        }
        return (c * c) % (mod);
    }
};