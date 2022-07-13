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
    bool canPartition(vector<int>& nums) {
        int sum = 0 , n = nums.size();
        for(auto x  : nums) sum += x;
        if(sum & 1){
            return false;
        }
        sum /= 2;
        vector<vector<int>> dp(n , vector<int>(sum + 1 , -1));
        int temp = 0;
        return solve(nums , sum , 0 , dp);
    }
};