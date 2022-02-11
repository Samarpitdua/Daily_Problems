class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<long long int>> dp(n , vector<long long int>(n , 0));
        if(n == 1)
            return grid[0][0];
        for(int i = 0 ; i < n ;i++)
        {
            dp[n - 1][i] = grid[n - 1][i];
        }
        for(int i = n - 2 ; i >= 0 ;i--)
        {
            for(int j = 0 ; j < n ; j++)
            {
                long long  ans = INT_MAX;
                
                for(int k = 0 ; k < n ;k++)
                {
                    
                    if(k != j)
                    {
                        ans = min(ans , dp[i + 1][k]);
                    }
                    
                }
                dp[i][j] = grid[i][j] + ans;
            }
        } 
        long long int ans = INT_MAX;
        for(int i = 0 ; i < n ;i++)
        {
            ans = min(ans , dp[0][i]);
        }
        return ans;
    }
};