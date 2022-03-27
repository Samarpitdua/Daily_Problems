class Solution {
public:
    int countOrders(int n) {
        long long pro = 1 , mod = 1000000007;
        for (int i = 1 ;  i < n + 1 ; ++i)
            pro = pro * i % mod;
        for (int i = 1 ;  i < 2 * n; i += 2) 
            pro = pro * i % mod;
    return pro;
    }
};