class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        map<int , set<int>> mp;
        for(auto x : logs)
        {
            mp[x[0]].insert(x[1]);
        }
        vector<int> ans(k , 0);
        for(auto x : mp)
        {
            int temp = x.second.size();
            ans[temp - 1]++;
        }
        return ans;
        
    }
};