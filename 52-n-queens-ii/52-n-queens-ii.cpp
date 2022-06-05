class Solution {
public:
    
    bool isValid(vector<string>& board,int row,int col,int n)
    {
        int duprow=row;
        int dupcol=col;
        while(col>=0 and row<n)
        {
            if(board[row][col]=='Q')
                return false;
            row++;
            col--;
        }
        row=duprow;
        col=dupcol;
        while(col>=0 and row>=0)
        {
            if(board[row][col]=='Q')
                return false;
            row--;
            col--;
        }
        row=duprow;
        col=dupcol;
        while(col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            col--;
        }
        return true;
    }
    void solve(int col,vector<vector<string>>& ans,vector<string>& board,int n)
    {
        if(col==n)
            ans.push_back(board);
        for(int i=0;i<n;i++)
        {
            if(isValid(board,i,col,n))
            {
                board[i][col]='Q';
                solve(col+1,ans,board,n);
                board[i][col]='.';
            }
        }
    }
    int totalNQueens(int n)  {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        solve(0,ans,board,n);
        return ans.size();
        
    }
};