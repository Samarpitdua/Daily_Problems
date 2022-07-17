class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = nums.size();
        for(auto q : queries) {
            set<pair<string,int>> st;
            for(int i = 0 ; i < n ; i++) 
            {
                st.insert({(nums[i].substr(nums[i].size() - q[1])) ,  i});
            }
            auto x = *std::next(st.begin(), q[0] - 1);
            ans.push_back(x.second);
            }
        return ans;
    }
};