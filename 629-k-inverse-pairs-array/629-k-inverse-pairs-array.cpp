#define mod 1000000007
class Solution {
public:
    int solve(int n, int k , vector<vector<int>>& dp) {
        if(!n)
            return 0;
        if(!k)
             return 1;
        if(dp[n][k] != -1)
            return dp[n][k];
        int ans = (solve(n - 1, k , dp) + mod - ((k - n) >= 0 ? solve(n - 1, k - n , dp) : 0)) % mod;
        return dp[n][k] = (solve(n ,k - 1 , dp) + ans) % mod;
    }
    int kInversePairs(int n, int k){
        vector<vector<int>> dp(n + 1, vector<int>(k + 1 , -1));
        return ((solve(n, k , dp) + mod - (k > 0 ? solve(n, k - 1 , dp) : 0)) % mod);
    }
};