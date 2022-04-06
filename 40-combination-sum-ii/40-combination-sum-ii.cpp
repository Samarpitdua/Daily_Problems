class Solution {
public:
    void solve(vector<vector<int>>& ans , vector<int>& temp , vector<int>& c , int target , int index , int n)
    {
        if(target == 0)
            ans.push_back(temp);
        if(target < 0)
            return;
        while(index < n)
        {
            temp.push_back(c[index]);
            solve(ans , temp , c , target - c[index] , index + 1 , n);
            temp.pop_back();
            while(index < (n - 1) and c[index] == c[index + 1])
                index++;
            index++;
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin() , candidates.end());
        solve(ans , temp , candidates , target , 0 , candidates.size());
        return ans;
     
    }
};