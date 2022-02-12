class Solution {
public:
    int solve(vector<int>& nums , int& target , int index , int sign , int ans)
    {
        if(index == 0)
        {
            if(sign == 0)
                ans -= nums[index];
            else
                ans += nums[0];
          //  cout<<ans<<" ";
            if(ans == target)
                return 1;
            else
                return 0;
        }
        if(sign == 0)
            ans -= nums[index];
        else
            ans += nums[index];
        return solve(nums , target , index - 1 , 1 , ans) + solve(nums , target , index - 1 , 0 , ans);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(nums , target , n - 1 , 1 , 0) + solve(nums , target , n  - 1 , 0 , 0);
    }
};