class Solution {
public:
    //nlogn approach using binary search
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0 , n = nums.size();
        vector<int> dp;
        for(int i = 0 ; i < n ;i++)
        {
            auto x = lower_bound(dp.begin() , dp.end() , nums[i]);
            if(x == dp.end())
                dp.push_back(nums[i]);
            else
            {
                *x = nums[i];
            }
        }
        return dp.size();
    }
};