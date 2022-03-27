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
        vector<vector<int>> dp(n + 1, vector<int>(2 , -1));
        int ans = solve(p , 0 , true , dp);
        return ans;
    }
};