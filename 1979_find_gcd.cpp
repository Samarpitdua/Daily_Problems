class Solution {
public:
    int findGCD(vector<int>& nums) {
        int p=*max_element(nums.begin(),nums.end());
        int q=*min_element(nums.begin(),nums.end());
        return __gcd(p,q);
    }
};
