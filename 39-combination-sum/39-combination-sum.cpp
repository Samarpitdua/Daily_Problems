class Solution {
public:
    void solve(vector<int> v ,int n, int i, int target , vector<vector<int>>& ans, vector<int> temp , int sum )
    {
        if(sum == target)
        {
            ans.push_back(temp);
            return;
        }
        
        if(sum > target or i >= n)
        {
            return;
        }
        // take it
        temp.push_back(v[i]);
        sum += v[i];
        solve(v , n , i , target , ans , temp , sum);
        //ignore it 
        temp.pop_back();
        sum -= v[i];
        solve(v , n , i + 1 , target , ans , temp , sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates , candidates.size() , 0 , target , ans , temp , 0);
        return ans;
        
    }
};