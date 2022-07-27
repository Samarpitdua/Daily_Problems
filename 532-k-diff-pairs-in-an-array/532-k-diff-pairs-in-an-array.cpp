class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size() , ct = 0;
        set<pair<int , int>> st;
        sort(nums.begin() , nums.end() , greater<int>());
        map<int , int> mp;
        for(int i = 0 ; i < n; i++)
        {
            if(mp.find(nums[i] + k) != mp.end())
            {
                if(st.find({nums[i] , nums[i] + k}) == st.end() and st.find({nums[i] , nums[i] + k}) == st.end())
                {
                    st.insert({nums[i] , nums[i] + k});
                }
            }
            mp[nums[i]]++;
            
        }
        return st.size();
    }
};