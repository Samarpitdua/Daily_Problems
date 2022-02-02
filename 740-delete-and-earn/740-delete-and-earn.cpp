class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin() , nums.end());
        vector<int> dp(maxi + 1 , 0);
        vector<int> sums(10001 , 0);
        for(int i = 0 ; i < n ;i++)
        {
            sums[nums[i]]++;
        }
        dp[0] = 0;
        dp[1] = sums[1];
        for(int i = 2 ; i <= maxi ; i++)
        {
            dp[i] = max(i * sums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[maxi];
            
        
        
    }
};