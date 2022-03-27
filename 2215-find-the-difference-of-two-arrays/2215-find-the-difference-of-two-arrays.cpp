class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        vector<int> temp , temp2;
        map<int ,int> mp , mp2;
        for(auto x : nums1)
            mp[x]++;
        for(auto x : nums2)
        {
            if(mp.find(x) == mp.end())
            {
                temp.push_back(x);
                mp[x] = -1;
            }
            else
                mp[x] = -1;
        }
        for(auto x : nums1)
        {
            if(mp[x] != -1)
            {
                temp2.push_back(x);
                mp[x] = -1;
            }
        }
        ans.push_back(temp2);
        ans.push_back(temp);
        return ans;
        
    }
};