class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxi = 0;
        for(auto x : accounts)
        {
            int ct = 0;
            for(auto y : x)
            {
                ct += y;
            }
            if(ct > maxi)
                maxi=ct;
        }
        return maxi;
        
    }
};