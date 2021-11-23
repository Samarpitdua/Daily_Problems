class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans=0,n=nums.size();
        vector<int>dp(n,0);
        for(int i=0;i<n;i++)
        {
            int maxi=0;
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    maxi=max(maxi,dp[j]);
                }
            }
            dp[i]=1+maxi;
        }
        for(auto x:dp)cout<<x<<" ";
        return *max_element(dp.begin(),dp.end());
    }
};
