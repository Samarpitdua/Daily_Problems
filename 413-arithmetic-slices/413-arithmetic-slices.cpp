class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
            return 0;
        vector<int> dp(n + 1 , 0);
        int ans = 0 , ct = 0;
        
        int temp = nums[1] - nums[0];
        for(int i = 2 ; i < n ;i++)
        {
            int cur_diff = nums[i] - nums[i - 1];
            if(temp == cur_diff)
                ct++;
            else
            {
                ct = 0 ; 
                temp = cur_diff;
            }
                ans += ct;
        }
        // for(auto x : dp)
        //     ans += x;
        return ans;
    }
};