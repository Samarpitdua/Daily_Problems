class Solution {
public:
    int countPoints(string rings) {
        unordered_map<int,set<char>>mp;
        for(int i = 0;i < rings.size();i += 2)
        {
            mp[rings[i+1]-'0'].insert(rings[i]);
        }
        int ans = 0;
        for(auto x:mp)
        {
            if(x.second.size() == 3)
                ans++;
        }
        return ans;
        
    }
};
