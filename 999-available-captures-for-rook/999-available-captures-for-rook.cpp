class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int ans = 0 , temp1 , temp2;
        for(int i = 0 ; i < 8 ;i++)
        {
            for(int j = 0 ; j < 8 ;j++)
            {
                if(board[i][j] == 'R')
                {
                    temp1 = i , temp2 = j;
                    break;
                }
            }
        }
        for(int i = temp1 ; i >= 0 ;i--)
        {
            if(board[i][temp2] == 'p')
            {
                ans++;
                break;
            }
            if(board[i][temp2] == 'B')
                break;
        }
        for(int i = temp1 ; i < 8 ;i++)
        {
            if(board[i][temp2] == 'p')
            {
                ans++;
                break;
            }
            if(board[i][temp2] == 'B')
                break;
        }
        for(int i = temp2 ; i >= 0 ;i--)
        {
            if(board[temp1][i] == 'p')
            {
                ans++;
                break;
            }
            if(board[temp1][i] == 'B')
                break;
        }
        for(int i = temp2 ; i < 8 ;i++)
        {
            if(board[temp1][i] == 'p')
            {
                ans++;
                break;
            }
            if(board[temp1][i] == 'B')
                break;
        }
        return ans;
    }
};