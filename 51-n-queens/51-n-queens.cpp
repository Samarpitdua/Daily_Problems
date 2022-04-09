class Solution {
public:
    bool isValid(int row , int col , vector<string>& board , int n)
    {
        for(int i = 0 ; i < col ;i++)
        {
            if(board[row][i] == 'Q')
                return false;
        }
        int i = row + 1, j = col - 1;
        while(i < n and j >= 0)
        {
            if(board[i][j] == 'Q')
                return false;
            i++ , j--;
        }
        i = row - 1, j = col - 1;
        while(i >= 0 and j >= 0)
        {
            if(board[i][j] == 'Q')
                return false;
            i-- , j--;
        }
        return true;
    }
void solve(vector<vector<string>>& ans , int n , vector<string>& temp , int col)
    {
        if(col == n)
        {
            ans.push_back(temp);
            return;
        }
        for(int i = 0 ; i < n ; i++)
        {
            if(isValid(i , col , temp , n))
            {
                temp[i][col] = 'Q';
                solve(ans , n , temp , col + 1);
                temp[i][col] = '.';
            }
        }
    }
        vector<vector<string>> solveNQueens(int n) {
            vector<vector<string>> ans;
            vector<string> temp(n);
            string s(n , '.');
            for(int i = 0 ; i < n ;i++)
                temp[i] = s;
            solve(ans , n , temp , 0);
            return ans;
    }
};