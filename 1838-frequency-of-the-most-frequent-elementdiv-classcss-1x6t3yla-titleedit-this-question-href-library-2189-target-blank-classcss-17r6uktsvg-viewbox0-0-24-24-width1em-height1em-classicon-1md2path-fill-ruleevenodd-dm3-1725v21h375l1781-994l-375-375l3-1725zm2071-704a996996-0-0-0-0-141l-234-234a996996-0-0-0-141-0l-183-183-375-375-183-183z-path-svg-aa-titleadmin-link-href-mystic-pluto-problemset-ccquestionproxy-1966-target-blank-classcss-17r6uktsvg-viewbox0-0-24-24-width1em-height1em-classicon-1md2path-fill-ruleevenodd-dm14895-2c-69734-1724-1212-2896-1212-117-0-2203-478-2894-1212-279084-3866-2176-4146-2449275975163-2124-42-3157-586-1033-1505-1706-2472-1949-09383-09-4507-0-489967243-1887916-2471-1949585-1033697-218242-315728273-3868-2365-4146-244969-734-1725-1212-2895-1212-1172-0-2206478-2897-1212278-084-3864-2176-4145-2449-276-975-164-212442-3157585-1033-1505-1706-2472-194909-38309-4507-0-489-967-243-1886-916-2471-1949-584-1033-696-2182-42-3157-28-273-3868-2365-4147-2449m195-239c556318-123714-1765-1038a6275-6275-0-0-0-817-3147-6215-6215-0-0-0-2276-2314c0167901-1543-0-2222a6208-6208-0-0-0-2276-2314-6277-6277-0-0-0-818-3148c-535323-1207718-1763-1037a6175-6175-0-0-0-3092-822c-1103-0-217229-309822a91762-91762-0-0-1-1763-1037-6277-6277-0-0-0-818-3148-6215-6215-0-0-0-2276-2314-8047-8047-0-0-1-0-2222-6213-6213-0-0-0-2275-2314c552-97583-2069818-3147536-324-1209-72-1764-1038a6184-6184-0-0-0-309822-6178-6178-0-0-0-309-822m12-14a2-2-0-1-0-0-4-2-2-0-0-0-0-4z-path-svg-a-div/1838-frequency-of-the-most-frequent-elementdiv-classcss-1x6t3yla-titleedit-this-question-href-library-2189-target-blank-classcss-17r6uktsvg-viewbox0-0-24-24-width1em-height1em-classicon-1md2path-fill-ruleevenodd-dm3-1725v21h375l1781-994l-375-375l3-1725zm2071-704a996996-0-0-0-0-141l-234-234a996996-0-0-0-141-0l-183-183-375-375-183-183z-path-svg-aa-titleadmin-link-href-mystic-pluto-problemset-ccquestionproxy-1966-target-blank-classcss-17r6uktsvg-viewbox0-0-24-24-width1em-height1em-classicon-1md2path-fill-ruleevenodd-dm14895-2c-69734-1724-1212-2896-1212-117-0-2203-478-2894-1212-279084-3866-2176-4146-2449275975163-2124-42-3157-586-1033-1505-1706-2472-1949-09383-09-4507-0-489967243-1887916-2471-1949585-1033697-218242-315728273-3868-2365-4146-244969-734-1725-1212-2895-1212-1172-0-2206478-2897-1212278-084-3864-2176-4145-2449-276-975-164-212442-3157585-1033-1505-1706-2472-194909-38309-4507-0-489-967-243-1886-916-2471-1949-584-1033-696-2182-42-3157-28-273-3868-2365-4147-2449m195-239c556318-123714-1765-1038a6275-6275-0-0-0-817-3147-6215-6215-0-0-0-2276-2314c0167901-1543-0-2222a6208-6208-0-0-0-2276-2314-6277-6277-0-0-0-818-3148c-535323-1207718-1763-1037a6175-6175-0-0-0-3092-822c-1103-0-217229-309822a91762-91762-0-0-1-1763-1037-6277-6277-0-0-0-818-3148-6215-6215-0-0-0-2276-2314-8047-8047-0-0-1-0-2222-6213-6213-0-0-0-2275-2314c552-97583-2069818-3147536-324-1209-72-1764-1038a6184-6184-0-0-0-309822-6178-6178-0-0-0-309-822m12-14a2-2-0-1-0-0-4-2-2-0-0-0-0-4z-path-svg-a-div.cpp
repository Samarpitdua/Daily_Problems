class Solution
{
    public:
        int maxFrequency(vector<int> &nums, int k)
        {
            sort(nums.begin(), nums.end());
            long long int ans=0 , sum = 0 , left = 0;
            for(int i =0 ;i < nums.size() ;i++){
                int start = 0;
                sum += nums[i];
                while((i - left + 1) * nums[i] - sum > k)
                    sum -= nums[left] , left++;
                ans = max(ans , i - left + 1);
            }
            return ans;
        }
};