class Solution {
public:
    int solve(vector<int>& nums , int i , int j , vector<vector<int>>& dp)
    {
        if(i > j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans= 0;
        for(int k = i ; k <= j ;k++)
        {
            ans = max(ans , nums[k] * nums[i - 1] * nums[j + 1] + solve(nums , i , k - 1 , dp) + solve(nums , k + 1 , j , dp));
        }
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin() , 1);
        vector<vector<int>> dp(n + 2 , vector<int>(n + 2 , -1));
        return solve(nums , 1 , n , dp);
        
    }
};