class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        map<int , int>mp;
        vector<int> ans;
            for(auto x : edges)
            {
                mp[x[1]]++;
            }
            for(int i = 0 ;i < n; i++)
            {
                if(!mp[i])
                {
                    ans.push_back(i);
                }
            }
        return ans;
    }
};