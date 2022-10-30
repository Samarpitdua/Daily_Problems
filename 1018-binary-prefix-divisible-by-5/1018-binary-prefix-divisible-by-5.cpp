class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size() , ct = 0;
        vector<bool> ans;
                for (auto i : nums) {
                    ct = (ct * 2 + i) % 5;
                    ans.push_back(!ct);
                }
          return ans;
    }
};