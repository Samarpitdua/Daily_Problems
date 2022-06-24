class Solution {
public:
    void solve(vector<int>& nums , vector<int> temp , vector<vector<int>>& ans , int n , int ind)
    {
        if(ind == n)
        {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        solve(nums , temp , ans , n , ind + 1);
        temp.pop_back();
        int i = ind + 1;
        for(; i < n ;i++)
        {
            if(nums[i] == nums[i - 1])
            {
                continue;
            }
            else
                break;
        }
        solve(nums , temp , ans , n , i);
        
        
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin() , nums.end());
        int n = nums.size();
        solve(nums , temp , ans , n , 0);
        return ans;
    }
};