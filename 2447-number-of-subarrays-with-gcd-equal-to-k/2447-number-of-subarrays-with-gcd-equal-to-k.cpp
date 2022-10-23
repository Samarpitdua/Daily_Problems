class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int ct = 0;
        for(int i = 0; i < nums.size() ;i++)
        {
            int gcd = nums[i];
            if(gcd == k)
                ct++;
            for(int j = i + 1 ; j < nums.size() ;j++)
            {
                gcd = __gcd(gcd , nums[j]);
                if(gcd == k)
                    ct++;
            }
        }
        return ct;
    }
};