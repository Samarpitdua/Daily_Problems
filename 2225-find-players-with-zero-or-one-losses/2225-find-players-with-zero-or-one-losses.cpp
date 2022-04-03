class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        map<int , int> mp,mp2;
        vector<int> temp1;
        vector<int> temp2;
        for(auto x : matches)
        {
            mp[x[0]]++;
            mp[x[1]]++;
        }
        for(auto x : matches)
        {
            mp2[x[1]]++;
        }
        for(auto x : mp2)
        {
            if(x.second == 1)
            {
                temp2.push_back(x.first);
            }
            mp[x.first] = -1;
        }
        mp2.clear();
        for(auto x : mp)
        {
            if(x.second != -1)
            {
                temp1.push_back(x.first);
            }
        }
        ans.push_back(temp1);
        ans.push_back(temp2);
        return ans;
    }
    
};