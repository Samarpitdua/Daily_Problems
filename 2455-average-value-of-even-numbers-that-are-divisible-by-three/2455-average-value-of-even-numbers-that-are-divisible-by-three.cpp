class Solution {
public:
    int averageValue(vector<int>& nums) {
        int ct = 0;
        int ans = 0;
        for(auto x : nums)
        {
            if(x % 6 == 0)
            {
                ans += x;
                ct++;
            }
        }
        if(ct == 0)
            return 0;
        return ans / ct;
    }
};