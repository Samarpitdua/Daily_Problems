class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        int ans = 0;
        for(int i = 0 ; k > 0 ; k--)
        {
                //nums[i] *= -1;
                if(i != (nums.size() - 1)  and nums[i + 1] < (nums[i]*-1))
                    nums[i]*=-1,i++;
            else
                nums[i] *= -1;
        }
        for(auto x : nums)
            ans += x;
        // ans = accumulate(nums.begin() , nums.end() ,sum);
        return ans;
    }
};