class Solution {
public:
    int solve(string& s , string& t , int i , int j , vector<vector<int>>&  dp)
    {
        if(i < 0 or j < 0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s[i] == t[j])
        {
            return dp[i][j] = 1 + solve(s , t , i - 1 , j - 1 , dp);
        }
        return dp[i][j] = max(solve(s , t , i - 1 , j , dp) ,  solve(s , t , i , j - 1 , dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size() , m = text2.size();
        vector<vector<int>> dp(n , vector<int>(m , -1));
        return solve(text1 , text2 , n - 1 , m - 1 , dp);
    }
};