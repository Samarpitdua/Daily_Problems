class Solution {
public:
    int solve(int start , int end , int m , int n , vector<vector<int>>& dp)
    {
        if(start > (m - 1) or end > (n - 1))
            return 0;
        if(start == m - 1 and end == n - 1)
            return 1;
        if(dp[start][end] != -1)
            return dp[start][end];
        return dp[start][end] = solve(start + 1 , end , m , n , dp) + solve(start , end + 1 , m , n , dp);
    }
    int uniquePaths(int m , int n) {
        vector<vector<int>> dp(m + 1 , vector<int>(n + 1 , -1));
        int ans = 0;
        return solve(0 , 0 , m , n , dp);
    }
};