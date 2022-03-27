class Solution {
public:
    int solve(vector<int>& p , int index , bool isBuyPossible , vector<vector<int>>& dp)
    {
        if(index == p.size())
            return 0;
        if(dp[index][isBuyPossible] != -1)
            return dp[index][isBuyPossible];
        if(isBuyPossible)
        {
            return dp[index][isBuyPossible] = max(-p[index] + solve(p , index + 1 , false , dp) , solve(p , index + 1 , true , dp));
        }
        else
             return dp[index][isBuyPossible] = max(p[index] + solve(p, index + 1 , true , dp) ,solve(p ,index + 1 ,false ,dp));
    }
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 , 0));
        
        for(int i = n - 1 ; i >= 0 ;i--)
        {
            for(int j = 0 ; j <= 1 ;j++)
            {
                if(j == 1)
                {
                    dp[i][j] = max(-p[i] + dp[i + 1][0] , dp[i+1][1]);
                }
                else
                {
                    dp[i][j] = max(p[i] + dp[i + 1][1] , dp[i + 1][0]);
                }
            }
        }
        return dp[0][1];
    }
};