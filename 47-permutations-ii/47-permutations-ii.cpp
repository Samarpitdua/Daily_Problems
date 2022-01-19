class Solution {
public:
    void solve2(vector<vector<int>>& ans , vector<int> nums , int ind)
    {
        if(ind == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i = ind ; i < nums.size() ;i++)
        {
            if(i == ind || nums[i] != nums[ind])
            {
                swap(nums[i] , nums[ind]);
                solve2(ans , nums ,ind + 1);
            }
        } 
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        vector<int> v;
       solve2(ans , nums ,0);
        return ans;
    }
};