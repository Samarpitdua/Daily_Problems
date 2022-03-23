class Solution {
public:
    //This is an in place answer we will take first row and first column as an additional aarray and store 0 in them if any of their row or column
    //have zro in them 
    void setZeroes(vector<vector<int>>& a) {
       
        int rows = a.size();
        bool col = false , row = false;
        int cols = a[0].size();
        for(int i = 0 ; i < rows ; i++)
        {
            if(a[i][0] == 0)
                col = true;
        }
        for(int i = 0 ; i < cols ; i++)
        {
            if(a[0][i] == 0)
                row = true;
        }
        for(int i=1;i<rows;i++)
        {
            for(int j=1;j<cols;j++)
            {
                if(a[i][j] == 0)
                {
                    a[0][j] = 0;
                    a[i][0] = 0;
                }
            }
        }
        for(int i = rows - 1 ; i >= 0 ; i--)
        {
            for(int j = cols - 1 ; j >= 0 ; j--)
            {
                if(i == 0 and row)
                {
                    a[i][j] = 0;
                }
                if(j == 0 and col)
                    a[i][j] = 0;
                if(a[0][j] == 0 or a[i][0] == 0)
                    a[i][j] = 0;
            }
        }
        if(col)
            a[0][0] = 0;
    }
};