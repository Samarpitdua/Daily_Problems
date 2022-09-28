class Solution {
public:
    void solve(int ind , vector<int>& nums , vector<int>& temp , vector<vector<int>>& ans)
    {
        if(ind == nums.size())
        {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        solve(ind + 1 , nums , temp , ans);
        temp.pop_back();
        int t = nums[ind];
        while(ind < nums.size() and nums[ind] == t)
            ind++;
        solve(ind , nums , temp , ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        //recursive function
        solve(0 , nums , temp , ans);
        return ans;
    }
};