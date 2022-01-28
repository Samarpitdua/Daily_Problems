class Solution {
public:
    void dfs(vector<vector<int>>& board , int i , int j , int rows , int cols)
    {
        if(board[i][j] == 1)
        {
            board[i][j] = -1;
            if(i + 1 < rows)
                dfs(board , i + 1, j , rows , cols );
            if(i - 1 >= 0)
                dfs(board , i - 1 , j , rows , cols);
            if(j + 1 < cols)
                dfs(board , i , j + 1 , rows , cols);
            if(j - 1 >= 0)
                dfs(board , i , j - 1, rows , cols);
        }
    }
        
    int numEnclaves(vector<vector<int>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        for(int i = 0 ; i < rows ;i++)
        {
            if(board[i][0] == 1)
            {
                dfs(board , i , 0 , rows , cols);
            }
            if(board[i][cols - 1] == 1)
            {
                dfs(board , i , cols - 1 , rows ,cols);
            }
        }
        for(int i = 0 ; i < cols ;i++)
        {
            if(board[0][i] == 1)
            {
                dfs(board , 0 , i ,rows ,cols);
            }
            if(board[rows - 1][i] == 1)
            {
                dfs(board , rows - 1 , i ,rows ,cols);
            }
        }
        int ct = 0;
        for(int i = 0 ; i < rows ;i++)
        {
            for(int j = 0 ;j < cols ;j++)
            {
                if(board[i][j] == 1)
                    ct++;
            }
        }
        return ct;
        
        return ct;
    }
};