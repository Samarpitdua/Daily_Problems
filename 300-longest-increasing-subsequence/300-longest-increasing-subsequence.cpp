class Solution {
public:
    //Using Binary Search
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp;
        for(auto x : nums)
        {
            auto it = lower_bound(dp.begin() , dp.end() , x);
            if(it == dp.end())
            {
                dp.push_back(x);
            }
            else{
                *it = x;
            }
        }
        for(auto x : dp)
            cout<<x<<" ";
        return dp.size();
    }
};