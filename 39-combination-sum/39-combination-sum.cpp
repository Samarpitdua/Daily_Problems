class Solution {
public:
    void solve(vector<int>& candy , int n , vector<int> temp , vector<vector<int>>& ans , int target , int index , int sum)
    {
        if(index == n)
        {
            if(target == 0)
            {
                ans.push_back(temp);
            }
            return;
        }
        if(candy[index] <= target){
            temp.push_back(candy[index]);
            solve(candy , n , temp , ans , target - candy[index] , index , sum);
          //  solve(candy , n , temp , ans , target - candy[index] , index + 1 , sum);
             temp.pop_back();
        }
        solve(candy , n , temp , ans , target , index + 1 , sum);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates , candidates.size() , temp ,ans , target , 0 , 0);
        return ans;
        
    }
};