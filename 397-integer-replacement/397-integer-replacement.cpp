class Solution {
public:
    int solve(long long int n , unordered_map<int , int>& dp)
    {
        if(n == 1)
            return 0;
        if(dp.find(n) != dp.end())
            return dp[n];
        if(n % 2 == 0)
        {
            return dp[n] = (1 + solve(n / 2 , dp));
        }
        else
        {
            return dp[n] = 1 + min(solve(n + 1ll , dp) , solve(n - 1ll , dp));
        }
    }
    int integerReplacement(int n) {
        unordered_map<int , int> dp;
        return solve(n , dp);
    }
};