class Solution {
public:
    int solve(int i , int j , int k , vector<vector<vector<int>>>& dp , vector<vector<int>>& grid, int m)
    {
        if(k == m)
        {
            return 0;
        }
        if(i < 0 or i == grid[0].size() or j < 0 or j == grid[0].size())
            return 0;
        
        if(dp[i][j][k] != -1)
            return dp[i][j][k];
        
        if(i == j)
        {
            return dp[i][j][k] = grid[k][i] + max({solve(i + 1 , j + 1 , k + 1, dp , grid , m) , solve(i - 1 , j + 1 , k + 1, dp , grid , m) , solve(i + 1 , j - 1 , k + 1, dp , grid , m) , solve(i - 1 , j - 1 , k + 1, dp , grid , m) , solve(i , j + 1 , k + 1, dp , grid , m) , solve(i , j - 1 , k + 1, dp , grid , m)  , solve(i + 1 , j , k + 1, dp , grid , m) , solve(i - 1 , j , k + 1, dp , grid , m) , solve(i , j, k + 1, dp , grid , m)});
        }
        else 
            return dp[i][j][k] = grid[k][j] + grid[k][i] + max({solve(i + 1 , j + 1 , k + 1, dp , grid , m) , solve(i - 1 , j + 1 , k + 1, dp , grid , m) , solve(i + 1 , j - 1 , k + 1, dp , grid , m) , solve(i - 1 , j - 1 , k + 1, dp , grid , m) , solve(i , j + 1 , k + 1, dp , grid , m) , solve(i , j - 1 , k + 1, dp , grid , m)  , solve(i + 1 , j , k + 1, dp , grid , m) , solve(i - 1 , j , k + 1, dp , grid , m) , solve(i , j, k + 1, dp , grid , m)});
    }
    
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector<vector<vector<int>>> dp(m , vector<vector<int>>(m , vector<int>(n , -1)));
        return solve(0 , m - 1 , 0 , dp , grid, n);
    }
};