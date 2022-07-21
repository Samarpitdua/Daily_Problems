class Solution {
public:
    void solve(vector<vector<int>>& ans , vector<int>& c , vector<int> temp , int tar , int ind){
        if(tar == 0){
            ans.push_back(temp);
            return;
        }
        if(ind < 0)
        {
            if(tar == 0)
                ans.push_back(temp);
            return;
        }
        if(tar >= c[ind]){
            temp.push_back(c[ind]);
            solve(ans , c , temp , tar - c[ind], ind - 1);
            temp.pop_back();
            while(ind > 0 and c[ind] == c[ind - 1])
            {
                ind--;
            }
            solve(ans , c , temp , tar , ind - 1);
        }
        else{
            solve(ans , c , temp , tar , ind - 1);
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        vector<vector<int>> ans;
        sort(c.begin() , c.end());
        vector<int> temp;
        int n = c.size();
        solve(ans , c , temp , target , n - 1);
        return ans;
    }
};