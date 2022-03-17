class Solution {
public:
    //always possible
    //delete all then insert all characters of next string
    //now find minimum
   //memoization 
    int solve(string word1, string word2, int i ,int j ,vector<vector<int>>& dp)
    {
        if(j == -1)
            return i + 1 ;
        if(i == -1)
            return j + 1;
        if(dp[i][j] != -1 )
            return dp[i][j];
            
        if(word1[i] == word2[j])
        {
            return dp[i][j] = solve(word1 , word2 , i - 1 , j - 1 , dp);
        }
        else
        {
            //replace -> insert -> delete
 return dp[i][j] = 1 + min({solve(word1 , word2 , i - 1 , j - 1 , dp) , solve(word1 , word2 , i , j - 1 , dp) , solve(word1 , word2 , i - 1 , j , dp)});
        }
    }
    
    
    //Tabulation
    int solve2(string word1, string word2, int m ,int n ,vector<vector<int>>& dp)
    {
        for(int i = 0 ; i <= m ;i++)
        {
            for(int j = 0  ; j <= n ;j++)
            {
                if(i == 0)
                    dp[i][j] = j;
                else if(j == 0)
                    dp[i][j] = i;
                else
                {
                    if(word1[i - 1] == word2[j - 1])
                        dp[i][j] = dp[i - 1][j - 1];
                    else
                        dp[i][j] = 1 + min({dp[i - 1][j - 1] , dp[i][j -1] , dp[i - 1][j]});
                }
            }
        }
        return dp[m][n];
    }
    int minDistance(string word1, string word2) {
        int m = word1.size() , n = word2.size();
        vector<vector<int>> dp (m + 1 , vector<int> (n + 1 , 0));
        return solve2(word1 , word2 , m , n , dp);
        //return solve(word1 , word2 , m - 1 , n - 1, dp);
    }
};