class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<pair<int , pair<int , int>>> v;
        int ans = 0 , ct = 0 , n = costs.size() / 2;
        for(auto x : costs)
        {
            v.push_back({x[0] - x[1], {x[0] , x[1]}});
        }
        sort(v.begin() , v.end());
        reverse(v.begin() , v.end());
        for(auto x : v)
        {
            if(ct < n)
                ans += x.second.second , ct++;
            else
                ans += x.second.first;
        }
        return ans;
    }
};