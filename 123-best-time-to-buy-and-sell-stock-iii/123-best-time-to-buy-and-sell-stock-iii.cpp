class Solution {
public:
    int solve(vector<int>& p , int index , bool isBuyPossible , vector<vector<vector<int>>>& dp , int transLeft)
    {
        if(index == p.size() or transLeft == 0)
            return 0;
        if(dp[index][isBuyPossible][transLeft] != -1)
            return dp[index][isBuyPossible][transLeft];
        if(isBuyPossible)
        {
            return dp[index][isBuyPossible][transLeft] = max(-p[index] + solve(p , index + 1 , false , dp , transLeft ) , solve(p , index + 1 , true , dp , transLeft ));
        }
        else
             return dp[index][isBuyPossible][transLeft] = max(p[index] + solve(p, index + 1 , true , dp , transLeft - 1) ,solve(p ,index + 1 ,false ,dp , transLeft ));
    }
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2 , vector<int>(3 , -1)));
        int ans = solve(p , 0 , true , dp , 2);
        return ans;
        
        return ans;
        
        
    }
};