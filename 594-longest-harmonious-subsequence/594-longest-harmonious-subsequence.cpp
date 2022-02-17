class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int , int> mp;
        for(auto x : nums)
            mp[x]++;
        
        int ans = 0 , p = -1 , temp , temp2;
        for(auto x : mp)
        {
            if(p == -1)
            {
                p = 1;
                temp = x.first;
                temp2 = x.second;
            }
            else
            {
                if(x.first == temp + 1)
                {
                    ans = max(ans , x.second + temp2);
                }
                    temp = x.first;
                    temp2 = x.second;
            }
        }
        return ans;
        
    }
};