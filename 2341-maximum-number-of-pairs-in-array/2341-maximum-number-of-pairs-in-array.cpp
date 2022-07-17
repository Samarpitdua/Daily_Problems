class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int , int> mp;
        for(auto x : nums){
            mp[x]++;
        }
        int ct1 =0 , ct2 = 0;
        vector<int> ans;
        for(auto x : mp){
            ct1 += x.second / 2;
            if(x.second & 1)
                ct2++;
        }
        ans.push_back(ct1);
        ans.push_back(ct2);
        return ans;
    }
};