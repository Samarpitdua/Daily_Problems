class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int , int> mp;
        int ct = 0;
        for(auto x : nums)
        {
            if(mp.find(k - x) != mp.end())
            {
                mp[k - x]--;
                if(mp[k - x] == 0)
                    mp.erase(k - x);
                ct++;
            }
            else
                mp[x]++;
        }
        return ct;
            
    }
};