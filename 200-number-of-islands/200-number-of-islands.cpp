class Solution {
public:
    void dfs(vector<vector<char>>& grid,int x,int y,int r ,int c )
    {
        if(x < 0 || x >= r || y < 0 || y >= c || grid[x][y] != '1')
            return;
        grid[x][y] = 0;
        dfs(grid, x + 1 , y , r , c);
        dfs(grid , x , y - 1 , r , c);
        dfs(grid , x - 1 , y , r , c);
        dfs(grid , x , y + 1 , r , c);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ct = 0;
        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0 ; j < grid[i].size() ; j++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(grid , i , j , grid.size(), grid[0].size());
                    ct ++;
                }
            }
        }
        return ct;
    }
};