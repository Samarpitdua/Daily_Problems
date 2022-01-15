class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int suff[n];
        int pref[n];
        int temp = 1;
        for(int i  = 0 ; i < n ; i++)
        {
            pref[i] = temp;
            temp *= nums[i];
        }
        temp = 1;
        for(int i = n - 1 ; i >= 0 ;i--)
        {
            suff[i] = temp;
            temp *= nums[i];
        }
        vector<int> ans(n);
        for(int i = 0 ; i < n ;i++)
        {
            ans[i] = pref[i] * suff[i];
        }
        return ans;
    }
};