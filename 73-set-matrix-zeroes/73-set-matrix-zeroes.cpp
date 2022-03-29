class Solution {
public:
    //This is an in place answer we will take first row and first column as an additional aarray and store 0 in them if any of their row or column
    //have zro in them 
    void setZeroes(vector<vector<int>>& a) {
       int m = a.size() , n = a[0].size();
        bool row = false , col = false;
    
        for(int i = 0 ; i < n ; i++)
        {
            if(a[0][i] == 0)
                col = true;
        }
        
        for(int i = 0 ; i < m ; i++)
        {
            if(a[i][0] == 0)
                row = true;
        }
        
        for(int i = 1 ; i < m ; i++)
        {
            for(int j = 1 ; j < n ; j++)
            {
                if(a[i][j] == 0)
                {
                    a[i][0] = 0;
                    a[0][j] = 0;
                }
            }
        }
        
        for(int i = m - 1 ; i > 0 ; i--)
        {
            for(int j = n - 1 ; j > 0 ; j--)
            {
                if(a[i][0] == 0)
                {
                    a[i][j] = 0;
                }
                if(a[0][j] == 0)
                {
                    a[i][j] = 0;
                }
            }
        }
        
        if(col)
        {
            for(int i = 0 ; i < n ; i++)
                a[0][i] = 0;
        }
        if(row)
        {
            for(int i = 0 ; i < m ; i++)
                a[i][0] = 0;
        }
        
    }
};