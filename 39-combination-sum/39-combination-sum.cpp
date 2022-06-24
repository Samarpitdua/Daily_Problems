class Solution {
public:
    void solve(vector<int>& can , vector<vector<int>>& ans , vector<int> temp , int tar , int ind)
    {
        if(ind == can.size())
        {
            if(0 == tar)
                ans.push_back(temp);
            return;
        }
        if(can[ind] <= tar)
        {
            temp.push_back(can[ind]);
            solve(can , ans , temp , tar - can[ind] , ind);
            temp.pop_back();
        }
            solve(can , ans , temp , tar , ind + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& can, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(can , ans , temp , target , 0);
        return ans;
    }
};