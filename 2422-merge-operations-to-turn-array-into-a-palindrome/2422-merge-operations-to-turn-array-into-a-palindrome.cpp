class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int l = 0 , r = n - 1;
        long long int lsum = 0 , rsum = 0;
        int ans = 0;
        int p = 0;
        while(l < r)
        {
            if(p == 0 or p == 1)
                lsum += nums[l];
            if(p == 0 or p == 2)
                rsum += nums[r];
            if(lsum == rsum)
            {
                l++ , r--;
                lsum = 0 , rsum = 0;
                p = 0;
                continue;
            }
            else if(lsum < rsum)
            {
                ans++;
                l++;
                p = 1;
            }
            else
            {
                ans++;
                r--;
                p = 2;
            }
        }
        return ans;
    }
};