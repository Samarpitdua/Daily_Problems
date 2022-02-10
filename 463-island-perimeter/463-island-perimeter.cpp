class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int r, int c, int &perimeter)
    {
        grid[i][j] = 2;
        if(i == 0 || grid[i-1][j] == 0)
            perimeter++;
        
        if(i == r || grid[i+1][j] == 0)
            perimeter++;
        
        if(j == 0 || grid[i][j-1] == 0)
            perimeter++;
        
        if(j == c || grid[i][j+1] == 0)
            perimeter++;
        
        if(i > 0 && grid[i-1][j] == 1)
            dfs(grid,i-1,j,r,c,perimeter);
        
        if(i < r && grid[i+1][j] == 1)
            dfs(grid,i+1,j,r,c,perimeter);
        
        if(j > 0 && grid[i][j-1] == 1)
            dfs(grid,i,j-1,r,c,perimeter);
        
        if(j < c && grid[i][j+1] == 1)
            dfs(grid,i,j+1,r,c,perimeter);
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int perimeter = 0;
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(grid[i][j] == 1)
                {
                    dfs(grid,i,j,r-1,c-1,perimeter);
					break;
                }
            }
        }
        return perimeter;
    }
};