class Solution {
public:
    //O(1) space
    void solve2(vector<vector<int>>& ans , vector<int> nums , int ind)
    {
        if(ind == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i = ind ; i < nums.size() ;i++)
        {
            swap(nums[i] , nums[ind]);
            solve2(ans , nums , ind + 1);
        } 
    }
    
    //O(n) space
    void solve(vector<vector<int>>& ans , vector<int> v , vector<int>& nums , map<int , int> mp)
    {
        if(v.size() == nums.size())
        {
            ans.push_back(v);
            return ;
        }
        for(auto x : nums)
        {
            if(mp.find(x) == mp.end())
            {
                mp[x] = 1;
                v.push_back(x);
                solve(ans , v , nums , mp);
                v.pop_back();
                mp.erase(x);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        map<int , int> mp;
        vector<int> v;
       // solve(ans , v ,  nums , mp);
       solve2(ans , nums ,0);
        return ans;
        
    }
};