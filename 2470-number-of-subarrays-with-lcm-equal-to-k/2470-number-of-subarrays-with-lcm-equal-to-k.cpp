class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int ct = 0;
        for(int i = 0 ; i < nums.size() ;i++)
        {
            long long int ans = nums[i];
            if(ans == k)
                    ct++;
            for(int j = i + 1 ; j < nums.size() ;j++)
            {
                long long temp = (nums[j] * ans) % 1000000007;
                ans = temp /__gcd((long long )nums[j], ans);
                if(ans == k)
                    ct++;
            }
        }
        return ct;
    }
};