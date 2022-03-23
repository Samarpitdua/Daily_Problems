class Solution {
public:
    void check(int i , int j , int n ,int m , vector<vector<int>>& board , vector<vector<int>>& ans)
    {
        int one =0 ,zero =0;
        if(i >= 1)
        {
            if(board[i - 1][j] == 1)
                one++;
        }
        if(j >= 1)
        {
            if(board[i][j - 1] == 1)
                one++;
        }
        if(i < (n - 1))
        {
            if(board[i + 1][j] == 1)
                one++;
        }
        if(j < (m - 1))
        {
            if(board[i][j + 1] == 1)
                one++;
        }
        if((i - 1) >= 0 and (j - 1) >= 0)
        {
            if(board[i - 1][j - 1] == 1)
                one++;    
        }
        if((i + 1) <= (n - 1) and (j - 1) >= 0)
        {
            if(board[i + 1][j - 1] == 1)
                one++;    
        }
        if((i - 1) >= 0 and (j + 1) <= (m - 1))
        {
            if(board[i - 1][j + 1] == 1)
                one++; 
        }
        if((i + 1) <= (n - 1) and (j + 1) <= (m - 1))
        {
            if(board[i + 1][j + 1] == 1)
                one++;    
        }
        if(board[i][j] == 1)
        {
            if(one < 2 or one > 3)
            {
                ans[i][j] = 0;
            }
        }
        else
        {
            if(one == 3)
                ans[i][j] = 1;
            
        }
            
    }
    void gameOfLife(vector<vector<int>>& board) {
         
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> ans(n , vector<int>(m , 0));
        ans = board;
        for(int i = 0 ; i < n ;i++)
        {
            for(int j = 0 ; j < m ;j++)
            {
                check(i , j ,n ,m , board , ans);
            }
        }
        board = ans;
    }
};