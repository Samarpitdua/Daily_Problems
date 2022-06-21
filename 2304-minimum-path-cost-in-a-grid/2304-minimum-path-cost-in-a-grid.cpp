class Solution {
public:
    int solve(int i , int j , vector<vector<int>>& grid, vector<vector<int>>& moveCost , vector<vector<int>>& dp)
    {
        if(i == grid.size() - 1)
            return grid[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        else
        {
            int temp = INT_MAX;
            for(int k = 0 ;k < grid[0].size() ; k++)
            {
                temp = min(temp , grid[i][j] + moveCost[grid[i][j]][k] + solve( i + 1,k , grid , moveCost , dp ));
            }
            return dp[i][j] = temp;
        }
        // return temp;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size() , n = grid[0].size();
        vector<vector<int>> dp(m , vector<int>(n , -1));
        int ans = INT_MAX;
        for(int i = 0 ; i < n ;i++)
        {
            ans = min(ans ,solve(0 , i ,grid, moveCost , dp) );
        }
        return ans;
    }
};