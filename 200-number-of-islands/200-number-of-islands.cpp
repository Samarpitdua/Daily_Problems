class Solution {
public:
    bool isValid(vector<vector<char>>& grid , vector<vector<int>>& vis , int m , int n ,int i , int j)
    {
        if(i < 0 or i >= m or j < 0 or j >= n or grid[i][j] == '0' or vis[i][j])
            return false;
        return true;
    }
    void dfs(vector<vector<char>>& grid , vector<vector<int>>& vis , int m , int n , int i , int j)
    {
        if(!isValid(grid , vis , m , n , i, j))
            return;
        vis[i][j] = 1;
        dfs(grid , vis , m , n , i + 1, j);
        dfs(grid , vis , m , n , i - 1, j);
        dfs(grid , vis , m , n , i , j + 1);
        dfs(grid , vis , m , n , i , j - 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size() , n = grid[0].size() , ct = 0;
        vector<vector<int>> vis(m , vector<int>(n , 0));
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ;j++)
            {
                if(!vis[i][j] and grid[i][j] == '1')
                {
                    ct++;
                    dfs(grid , vis, m , n , i , j);
                }
            }
        }
        return ct;
    }
};