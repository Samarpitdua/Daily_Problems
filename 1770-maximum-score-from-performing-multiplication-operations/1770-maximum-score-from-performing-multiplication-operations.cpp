class Solution {
public:
    int solve(vector<int>& nums, vector<int>& m , int ind , int l , int r , vector<vector<int>>& dp)
    {
        if(ind == m.size())
            return 0;
        if(dp[ind][l] != INT_MIN)
            return dp[ind][l];
        int a = (nums[l] * m[ind]) + solve(nums , m , ind + 1, l + 1, r , dp);
        int b = (nums[r] * m[ind]) + solve(nums , m , ind + 1, l , r - 1 , dp);
        return dp[ind][l] = max(a , b);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int ans = 0;
        int n = nums.size();
        int m = multipliers.size();
        vector<vector<int>>dp(m , vector<int>(m , INT_MIN));
        return solve(nums , multipliers , 0 , 0 , n - 1 , dp);
    }
};