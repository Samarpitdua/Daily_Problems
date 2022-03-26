class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        long long pro = 1;
        if(k <= 1)
            return 0;
        int n = nums.size();
        for(int i = 0 , j = 0 ; j < n ; j++)
        {
            pro *= nums[j];
            if(pro >= k )
            {
                while(pro >= k)
                {
                    pro /= nums[i];
                    i++;
                }
            }
            ans += (j - i + 1);   
        }
        return ans;
    }
};