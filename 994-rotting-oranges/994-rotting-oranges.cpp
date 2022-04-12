class Solution {
public:
    bool isValid( vector<vector<int>>& grid , int i , int j )
    {
        if ( i < grid.size() and j < grid[0].size() and i >= 0 and j >= 0 and grid[i][j] == 1)
        {
            //grid[i][j] = 2;
            return true;
        }
        return false;
        
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        queue<pair<int , int>> q;
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ;j++)
            {
                if(grid[i][j] == 2)
                {
                   
                        q.push({i + 1 , j});
                    
                        q.push({i - 1 , j});
                    
                        q.push({i , j - 1});
                    
                        q.push({i , j + 1});
                }
            }
        }
         cout<<q.size()<<" ";
        while(!q.empty())
        {
            int p = 0;
            int sz = q.size();
            for(int i = 0 ; i < sz ;i++)
            {
                int i2 = q.front().first;
                int j = q.front().second;
                q.pop();
                if(isValid(grid , i2 , j))
                {
                    p = 1;
                    grid[i2][j] = 2;
                    q.push({i2 + 1 , j});
                    
                        q.push({i2 - 1 , j});
                    
                        q.push({i2 , j - 1});
                
                        q.push({i2 , j + 1});
                }
            }
            if(p)
                ans++;
        }
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ;j++)
            {
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        return ans;
    
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         queue<pair<int,int>>q;
//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(grid[i][j]==2)
//                 {
//                     q.push({i-1,j}),q.push({i+1,j}),q.push({i,j-1}),q.push({i,j+1});
//                 }
//             }
//         }
//         int ct=0;
//         while(!q.empty())
//         {
//             int p=-1;
//             int b=q.size();
//             for(int i=0;i<b;i++)
//             {
//                 int l=q.front().first;
//                 int r=q.front().second;
//                 q.pop();
//                 //cout<<l<<" "<<r<<endl;
//                 if(l>=0 and r>=0 and l<m and r<n and grid[l][r]==1)
//                 {
//                    grid[l][r]=2;
//                     q.push({l-1,r}),q.push({l+1,r}),q.push({l,r-1}),q.push({l,r+1});
//                     p=1;
//                 }
                
//             }
//             if(p==1)
//             {
//                 ct++;
//                 p=-1;
//             }
//             else
//                 break;
//         }
//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(grid[i][j]==1)
//                     return -1;
//             }
//         }
//         return ct;
        
     }
};