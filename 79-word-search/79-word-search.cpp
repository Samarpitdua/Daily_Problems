class Solution {
public:
    bool isValid(int i , int j , int m , int n)
    {
        if(i >= 0 and i < m and j >= 0 and j < n )
            return true;
        return false;
    }
    bool solve(int i , int j , int m , int n , string word , int ind , vector<vector<char>>& board)
    {
        if(ind == word.size())
            return true;
        else
        {
            bool a = false , b = false, c = false ,d = false;
            if(isValid(i + 1 , j , m , n) and board[i + 1][j] == word[ind])
            {
                board[i + 1][j] = '#';
                a =  solve(i + 1 , j , m , n , word , ind + 1 , board);
                board[i + 1][j] = word[ind];
            }
            if(isValid(i , j + 1, m , n) and board[i][j + 1] == word[ind])
            {
                board[i][j + 1] = '#';
                b =  solve(i , j + 1 , m , n , word , ind + 1 , board);
                board[i][j + 1] = word[ind];
            }
            if(isValid(i - 1 , j , m , n) and board[i - 1][j] == word[ind])
            {
                board[i - 1][j] = '#';
                c =  solve(i - 1 , j , m , n , word , ind + 1 , board);
                board[i - 1][j] = word[ind];
            }
            if(isValid(i , j - 1 , m , n) and board[i][j - 1] == word[ind])
            {
                board[i][j - 1] = '#';
                d =  solve(i , j - 1 , m , n , word , ind + 1 , board);
                board[i][j - 1] = word[ind];
            }
            return a or b or c or d;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size() , n = board[0].size();
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ;j++)
            {
                if(board[i][j] == word[0])
                {
                //    cout<<5;
                    board[i][j] = '#';
                    if(solve(i , j , m , n , word , 1 , board))
                        return true;
                    board[i][j] = word[0];
                }
            }
        }
        return false;
    }
};