class Solution {
public:
    int solve(int i , int j1 , int j2 , vector<vector<int>>& grid , vector<vector<vector<int>>>& dp, int m , int n)
    {
        if(j1 >= n or j1 < 0 or j2 >= n or j2 < 0)
            return -1e8;
        if(i == m - 1){
            if(j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        int maxi = -1e8;
        for(int j11 = -1 ; j11 <= 1 ;j11++){
            for(int j22 = -1 ;j22 <= 1 ;j22++){
                int val = 0;
                if(j1 == j2)
                    val += grid[i][j1];
                else
                    val += grid[i][j1] + grid[i][j2];
                maxi = max(maxi , val + solve(i + 1 , j1 + j11 , j2 + j22, grid , dp , m, n));
                    
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<vector<int>>> dp(rows , vector<vector<int>>(cols , vector<int>(cols , -1)));
        return solve(0 , 0 , cols - 1 , grid , dp , rows , cols);
        
    }
};