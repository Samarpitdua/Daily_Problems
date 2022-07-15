class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j,int rows,int cols,int& ct)
    {
        if(i<0 or j<0 or i>=rows or j>=cols or grid[i][j]==0)
            return;
        ct++;
        grid[i][j]=0;
        dfs(grid,i+1,j,rows,cols,ct);
        dfs(grid,i,j+1,rows,cols,ct);
        dfs(grid,i-1,j,rows,cols,ct);
        dfs(grid,i,j-1,rows,cols,ct);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int maxi=0;
        int ct;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                ct=0;
                if(grid[i][j]==1)
                {
                    dfs(grid,i,j,rows,cols,ct);
                    if(ct>maxi)maxi=ct;
                }
            }
        }
        return maxi;
    }
};