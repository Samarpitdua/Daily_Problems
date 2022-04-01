class Solution {
public:
    void solve(int i, int target, vector<int> &v, vector<vector<int>> &ans, vector<int>& temp){
    if(target == 0)
        {
            ans.push_back(temp);
            return;
        }       
        for(int j = i ; j < v.size() ;j++)
        {
            if(j > i && v[j] == v[j - 1])
                continue;
            if(v[j] > target)
                break;
            temp.push_back(v[j]);
            solve(j + 1 , target - v[j], v , ans , temp);
            temp.pop_back();
            //cout<<"hi";
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin() , candidates.end());
        // solve(candidates , 0 , target , ans , temp);
        solve(0 , target ,candidates, ans , temp);
        return ans;
     
    }
};