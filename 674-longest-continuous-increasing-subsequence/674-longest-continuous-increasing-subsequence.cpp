class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ct = 1 , ans = 1;
        for(int i = 1 ; i < nums.size() ;i++)
        {
            if(nums[i] > nums[i - 1])
                ct++;
            else ct = 1;
            ans = max(ans , ct);
        }
        return ans;
    }
};