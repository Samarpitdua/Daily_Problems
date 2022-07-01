class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<int> ans;
        int n = nums.size();
        if(n == 1)
        {
            return nums;
        }
        for(int i = 0 ;i < n ;i++)
        {
            if(i == 0)
            {
                if(nums[1] > (nums[0] + 1))
                    ans.push_back(nums[i]);
            }
            else if(i == n - 1)
            {
                if(nums[n - 1] > (nums[n - 2] + 1))
                    ans.push_back(nums[i]);
            }
            else
            {
                if(((nums[i] + 1) < (nums[i + 1])) and ((nums[i - 1] + 1) < (nums[i])))
                    ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};