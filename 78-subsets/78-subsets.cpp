class Solution {
public:
    void solve(vector<int>& nums, vector<int> temp , int index , int n , vector<vector<int>>& ans)
    {
        ans.push_back(temp);
            while(index < n)
            {
                temp.push_back(nums[index]);
                solve(nums , temp , index + 1 , n , ans);
                temp.pop_back();
                index++;
            }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        solve(nums , temp , 0 , n , ans);
        return ans;
        
        
    }
};