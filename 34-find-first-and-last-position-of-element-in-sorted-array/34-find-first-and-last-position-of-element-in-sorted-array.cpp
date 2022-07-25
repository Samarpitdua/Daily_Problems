class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        
        int ans1 = - 1, ans2 = -1;
        ans2 = lower_bound(nums.begin() , nums.end() , target) - nums.begin();
        ans1 = upper_bound(nums.begin() , nums.end() , target) - nums.begin();
        ans1--;
        if(ans1 < 0 or nums[ans1] != target)
        {
            ans1 = ans2 = -1;
        }
       vector<int> ans = {ans2 , ans1};
        // ans.push_back(ans1);
        return ans;
    }
};