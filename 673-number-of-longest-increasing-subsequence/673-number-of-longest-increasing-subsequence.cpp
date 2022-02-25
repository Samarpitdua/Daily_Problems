class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int ans = 0 , n = nums.size();
        vector<int> dp(n , 1) , dp2(n , 1);
        for(int i = 1 ; i < n ;i++)
        {
            int maxi = 0 , ct = 0;
            for(int j = 0 ; j < i ;j++)
            {
                if(nums[i] > nums[j])
                {
                    if((dp[j] + 1) > dp[i])
                        dp[i] = dp[j] + 1 , ct = dp2[j];
                    else if((dp[j] + 1) == dp[i])
                        ct += dp2[j];
                }
            }
            dp2[i] = max(dp2[i] , ct);
        }
        int temp = *max_element(dp.begin() , dp.end());
        for(int i = 0 ; i < n ; i++)
        {
            if(dp[i] == temp)
                ans += dp2[i];
        }
        return ans;
        
    }
};