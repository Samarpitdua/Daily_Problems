class Solution {
public:
    bool solve(vector<int>& nums , int sum , int ind , vector<vector<int>>& dp){
        if(ind == nums.size())
            return sum == 0;
        if(dp[ind][sum] != -1)
            return dp[ind][sum];
        int take = 0 , notTake;
        if(nums[ind] <= sum)
             take = solve(nums , sum  - nums[ind], ind + 1 , dp );
        notTake = solve(nums , sum , ind + 1 , dp );
        return dp[ind][sum] = take || notTake;
    }
    bool solve2(vector<int>& nums , int sum , int ind , vector<vector<int>>& dp){
        int n = nums.size();
        for(int i = 0 ; i <= n ;i++)
        {
            for(int j = 0; j  <= sum ;j++)
            {
                if(j == 0)
                {
                    dp[i][j] = 1;
                }
                else if(i == 0)
                    dp[i][j] = 0;
            }
        }
        for(int i = 1 ; i <= n ;i++)
        {
            for(int j = 1; j <= sum ;j++)
            {
                if(nums[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j-nums[i - 1]] || dp[i - 1][j];
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][sum];
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0 , n = nums.size();
        for(auto x  : nums) sum += x;
        if(sum & 1){
            return false;
        }
        sum /= 2;
        vector<vector<int>> dp(n + 1 , vector<int>(sum + 1 , 0));
        int temp = 0;
        return solve2(nums , sum , 0 , dp);
    }
};