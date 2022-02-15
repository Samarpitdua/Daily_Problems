class Solution {
public:
    int solve(vector<int>& coins , int amount , vector<vector<int>>& dp , int index)
    {
        if(index == 0)
        {
            if(amount % coins[index] == 0)
            {
                return amount/coins[0] ;
            }
            else
                return 1e9;
        }
        if(dp[index][amount] != -1)
            return dp[index][amount];
        int notTake = solve(coins , amount , dp , index - 1);
        int take = 1e9;
        if(coins[index] <= amount)
            take = 1+ solve(coins , amount - coins[index] , dp , index);
        return dp[index][amount] = min(take , notTake);
    }
    int coinChange(vector<int>& coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>>dp( n + 1 , vector<int>(amount + 1 , -1));
        int ans = solve(coins , amount , dp , n - 1);
        if(ans >= 1e9)
            return -1;
        return ans;
    }
};