class Solution {
public:
    bool isValid(int x , int y , vector<vector<int>>& vis , int n, vector<vector<int>>& grid)
    {
            if(x >= 0 and x < grid.size() and y >= 0 and y < grid.size() and vis[x][y] == -1)
            {
                vis[x][y] = 1;
                return (grid[x][y] == 0);
            }
        return false;
     }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair< int , int >> q;
        int ct = 0;
        vector<vector< int >> directions = {{1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,-1},{-1,0}};
        vector<vector<int>> vis(n , vector<int>(n , -1));
        
        if(grid[0][0] == 1 or grid[n - 1][n - 1] == 1)
            return -1;
    
        q.push({0 ,0});
        ct++;
        if(n == 1)
            return 1;
        
        while(!q.empty())
        {
            int sz = q.size();
            ct++;
            //cout<<sz<<" : "<<ct<<"\n";
            vis[0][0] = 1;
            
            for(int i = 0 ; i < sz ; i++)
            {
                int temp = q.front().first;
                int temp2 = q.front().second;
                q.pop();
                for(int j = -1 ; j <= 1; j++)
                {
                    for(int k=-1 ; k <= 1; k++)
                    {
                        if(j == 0 and k == 0)
                            continue;
                        
                        if(isValid(temp + j , temp2 + k , vis , n, grid))
                        {

                            q.push({temp + j , temp2 + k});
                            if((temp + j )== n - 1 and (temp2 + k) == n - 1)
                                return ct;
                        }
                    }
                }
            }
        }
        return -1;
    }
};