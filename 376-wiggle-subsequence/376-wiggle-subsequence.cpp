class Solution {
public:
    int solve(int ind , vector<int>& nums , int n , vector<vector<int>>& dp , bool flag){
        if(ind == n - 1)
            return 1;
        if(dp[ind][flag] != -1)
            return dp[ind][flag];
        int ans = 0;
        if(flag)
        {
            if(nums[ind + 1] > nums[ind])
            {
                ans = max(ans , 1 + solve(ind + 1 , nums , n ,dp , false));
            }
            else
                ans = max(ans , solve(ind + 1 , nums , n ,dp , true));
                
        }
        else
        {
            if(nums[ind + 1] < nums[ind])
            {
                ans = max(ans , 1 + solve(ind + 1 , nums , n , dp , true));
            }
            else
                ans = max(ans , solve(ind + 1 , nums , n ,dp , false));
        }
        return dp[ind][flag] = ans;
    }
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1 , vector<int>(2 , -1));
        int ans = -1;
        ans = max(ans , solve(0 , nums , n , dp , true));
        ans = max(ans , solve(0 , nums , n , dp , false));
        return ans;
    }
};