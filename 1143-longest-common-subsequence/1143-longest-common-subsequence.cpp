class Solution {
public:
    int solve(string& s , string& t , int m , int n , vector<vector<int>>& dp){
        if(m < 0 or n < 0)
            return 0;
        if(dp[m][n] != -1)
            return dp[m][n];
        if(s[m] == t[n]){
            return dp[m][n] = 1 + solve(s , t ,m - 1 , n - 1 , dp);
        }
        else
            return dp[m][n] = max(solve(s , t , m - 1 , n , dp) , solve(s , t ,m , n - 1 , dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size() , n = text2.size();
        vector<vector<int>> dp(m , vector<int>(n , -1));
        return solve(text1 , text2 , m - 1, n - 1, dp);
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        // int n = text1.size() , m = text2.size();
        // vector<vector<int>> dp(n + 1 , vector<int> (m + 1 , 0));
        // for(int i = 1 ; i <= n ;i++)
        // {
        //     for(int j = 1 ; j <= m ;j++)
        //     {
        //         if(text1[i - 1] == text2[j - 1])
        //         {
        //             dp[i][j] = 1 + dp[i - 1][j - 1];
        //         }
        //         else
        //             dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
        //     }
        // }
        // return dp[n][m];
    }
};