class Solution {
public:
    bool valid(vector<vector<int>>& grid , int i , int j)
    {
        if(i >=0 and j >=0 and i < grid.size() and j < grid[0].size() and grid[i][j] == 1)
        {
            return true;
        }
        return false;
    }
    void dfs(int i , int j , int row0 , int col0 , vector<vector<int>>& grid, vector<pair<int , int>>& temp)
    {
        grid[i][j] = 0;
        temp.push_back({i - row0, j - col0});
        if(valid(grid , i + 1, j))
        {
            dfs(i + 1, j , row0 , col0 , grid , temp);
        }
        if(valid(grid , i, j + 1))
        {
            dfs(i , j  + 1, row0 , col0 , grid , temp);
        }
        if(valid(grid , i - 1, j))
        {
            dfs(i - 1, j , row0 , col0 , grid , temp);
        }
        if(valid(grid , i, j - 1))
        {
            dfs(i , j - 1, row0 , col0 , grid , temp);
        }
        
    }
    int numDistinctIslands(vector<vector<int>>& grid) {
        set<vector<pair<int , int>>> ans;
        int n = grid.size() , m = grid[0].size();
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j < m ;j++)
            {
                if(grid[i][j] == 1)
                {
                    vector<pair<int , int>> temp;
                   dfs(i , j , i , j , grid , temp);
                    ans.insert(temp);
                }
            }
        }
        return ans.size();
    }
};