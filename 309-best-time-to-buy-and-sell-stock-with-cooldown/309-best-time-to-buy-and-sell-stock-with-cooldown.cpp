class Solution {
public:
    int solve(vector<int>& p , int index , int isBuyPossible , vector<vector<int>>& dp)
    {
        if(index == p.size())
            return 0;
        if(dp[index][isBuyPossible] != -1)
            return dp[index][isBuyPossible];
        if(isBuyPossible == 2)
        {
            return dp[index][isBuyPossible] = max(-p[index] + solve(p , index + 1 , 0 , dp) , solve(p , index + 1 , 2 , dp));
        }
        else if(isBuyPossible == 0)
             return dp[index][isBuyPossible] = max(p[index] + solve(p, index + 1 , 1 , dp) ,solve(p ,index + 1 , 0 ,dp));
        else
            return dp[index][isBuyPossible] = solve(p , index + 1 , 2 , dp);
            
    }
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(3 , -1));
        int ans = solve(p , 0 , 2 , dp);
        return ans;
        
    }
};