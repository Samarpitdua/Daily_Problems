class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0 , n = nums.size();
        vector<int> dp(n , 1);
        dp[0] = 1;
        for(int i = 1 ; i < n ;i++)
        {
            for(int j = 0 ; j < i ;j++)
            {
                if(nums[i] > nums[j])
                {
                    dp[i] = max(1 + dp[j] , dp[i]);
                }
            }
        }
        return *max_element(dp.begin() , dp.end());
    }
};