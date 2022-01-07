class Solution {
public:
    void calculate(vector<long long>& prime , int n)
    {
        for(int i = 2 ; i <= sqrt(n) ; i++)
        {
            if(prime[i] == 1)
            {
                for(int j = i * i; j < n ; j += i)
                    prime[j] = 0;
                prime[i] = 1;
            }
        }
    }
    int countPrimes(int n) {
        vector<long long> prime(n , 1);
        //prime[0] = prime[1] = false;
        
        calculate(prime , n);
        
        int ans = 0;
        
        for(int i = 2 ; i < n ; i++)
        {
            if(prime[i]) ans ++ ;
        }
        return ans;
        
    }
};