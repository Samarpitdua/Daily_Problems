class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int ,int> mp;
        for(auto x : answers)
            mp[x]++;
        int ans = 0;
        for(auto x : mp)
        {
            int nop = x.first + 1;
            int ct = ceil(x.second/double(nop));
            ans += (nop * ct);
        }
        return ans;
    }
};