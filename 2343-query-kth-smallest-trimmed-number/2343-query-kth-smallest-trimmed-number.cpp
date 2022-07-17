class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        int n = nums.size();
        for(auto &q : queries) {
            set<pair<string,int>> st;
            for(int i=0;i<n; i++) {
                st.insert({(nums[i].substr(nums[i].size()-q[1])), i});
                // pq.push_back({(nums[i].substr(nums[i].size()-q[1])), i});
            }
            auto x = *std::next(st.begin(), q[0] - 1);
            res.push_back(x.second);
            }
        return res;
    }
};