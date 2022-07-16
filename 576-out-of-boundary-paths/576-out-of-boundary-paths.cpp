#define mod 1000000007
class Solution {
public:
    int solve(int m , int n , int k , int srr , int src , vector<vector<vector<int>>>& dp){
     
        if(src < 0 or srr < 0 or srr >= m or src >= n){
                return 1;
        }
        if(!k)
            return 0;
        if(dp[srr][src][k] != -1)
            return dp[srr][src][k];
        long long int ans = 0;
        if(k){
            ans += solve(m , n , k - 1 , srr + 1, src , dp) % mod;
            ans += solve(m , n , k - 1 , srr , src + 1 , dp) % mod;
            ans += solve(m , n , k - 1 , srr - 1 , src , dp) % mod;
            ans += solve(m , n , k - 1 , srr , src - 1 , dp) % mod;
        }
        return dp[srr][src][k] = ans % mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m , vector<vector<int>>(n , vector<int>(maxMove + 1 , -1)));
        return solve(m , n, maxMove , startRow , startColumn , dp);
    }
};