class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xxor = 0;
        for(auto x : nums)xxor ^= x;
        return xxor;
    }
};