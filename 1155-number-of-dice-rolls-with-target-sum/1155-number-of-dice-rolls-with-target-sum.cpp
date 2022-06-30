#define mod 1000000007;
class Solution {
public:
    int solve(int n , int k , int target , vector<vector<long long int>>& dp){
        
        if(n == 0 or target <= 0)
            return target == n;
        if(dp[n][target] != -1)
            return dp[n][target];
        
        long long int ans = 0;
        for(int i = 1 ; i <= k ;i++)
        {
            ans = ans + solve(n - 1, k , target - i , dp);
            ans %= mod;
        }
        dp[n][target] = ans % mod;
        return ans % mod ;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long int>> dp(n + 1 , vector<long long int>(target + 1 , -1));
        return solve(n , k, target , dp);
    }
};