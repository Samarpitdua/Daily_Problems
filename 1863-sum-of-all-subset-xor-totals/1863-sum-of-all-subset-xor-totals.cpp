class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int orz = 0;
        for(auto x : nums)
            orz |= x;
        return orz * pow(2 , nums.size() - 1);
    }
};