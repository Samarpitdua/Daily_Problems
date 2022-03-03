class Solution {
public:
    int solve(string& s , string& p , int i , int j , vector<vector<int>>& dp)
    {
        if(j == -1)
        {
            return i == j ; 
        }
        if(i == -1)
        {
            if(p[j] != '*')
                return 0;
            return solve(s , p , i , j - 1 , dp);
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(p[j] == '*')
        {
    return dp[i][j] = (solve(s , p , i - 1 , j , dp) || solve(s , p , i , j - 1 , dp));
        }
        else
        {
            if(i >= 0 and ( (s[i] == p[j]) or p[j] == '?'))
                return dp[i][j] = solve(s , p , i - 1 , j - 1 , dp);
            return 0;
        }
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , -1));
        return solve(s , p , n - 1 , m - 1 , dp);
        
    }
};