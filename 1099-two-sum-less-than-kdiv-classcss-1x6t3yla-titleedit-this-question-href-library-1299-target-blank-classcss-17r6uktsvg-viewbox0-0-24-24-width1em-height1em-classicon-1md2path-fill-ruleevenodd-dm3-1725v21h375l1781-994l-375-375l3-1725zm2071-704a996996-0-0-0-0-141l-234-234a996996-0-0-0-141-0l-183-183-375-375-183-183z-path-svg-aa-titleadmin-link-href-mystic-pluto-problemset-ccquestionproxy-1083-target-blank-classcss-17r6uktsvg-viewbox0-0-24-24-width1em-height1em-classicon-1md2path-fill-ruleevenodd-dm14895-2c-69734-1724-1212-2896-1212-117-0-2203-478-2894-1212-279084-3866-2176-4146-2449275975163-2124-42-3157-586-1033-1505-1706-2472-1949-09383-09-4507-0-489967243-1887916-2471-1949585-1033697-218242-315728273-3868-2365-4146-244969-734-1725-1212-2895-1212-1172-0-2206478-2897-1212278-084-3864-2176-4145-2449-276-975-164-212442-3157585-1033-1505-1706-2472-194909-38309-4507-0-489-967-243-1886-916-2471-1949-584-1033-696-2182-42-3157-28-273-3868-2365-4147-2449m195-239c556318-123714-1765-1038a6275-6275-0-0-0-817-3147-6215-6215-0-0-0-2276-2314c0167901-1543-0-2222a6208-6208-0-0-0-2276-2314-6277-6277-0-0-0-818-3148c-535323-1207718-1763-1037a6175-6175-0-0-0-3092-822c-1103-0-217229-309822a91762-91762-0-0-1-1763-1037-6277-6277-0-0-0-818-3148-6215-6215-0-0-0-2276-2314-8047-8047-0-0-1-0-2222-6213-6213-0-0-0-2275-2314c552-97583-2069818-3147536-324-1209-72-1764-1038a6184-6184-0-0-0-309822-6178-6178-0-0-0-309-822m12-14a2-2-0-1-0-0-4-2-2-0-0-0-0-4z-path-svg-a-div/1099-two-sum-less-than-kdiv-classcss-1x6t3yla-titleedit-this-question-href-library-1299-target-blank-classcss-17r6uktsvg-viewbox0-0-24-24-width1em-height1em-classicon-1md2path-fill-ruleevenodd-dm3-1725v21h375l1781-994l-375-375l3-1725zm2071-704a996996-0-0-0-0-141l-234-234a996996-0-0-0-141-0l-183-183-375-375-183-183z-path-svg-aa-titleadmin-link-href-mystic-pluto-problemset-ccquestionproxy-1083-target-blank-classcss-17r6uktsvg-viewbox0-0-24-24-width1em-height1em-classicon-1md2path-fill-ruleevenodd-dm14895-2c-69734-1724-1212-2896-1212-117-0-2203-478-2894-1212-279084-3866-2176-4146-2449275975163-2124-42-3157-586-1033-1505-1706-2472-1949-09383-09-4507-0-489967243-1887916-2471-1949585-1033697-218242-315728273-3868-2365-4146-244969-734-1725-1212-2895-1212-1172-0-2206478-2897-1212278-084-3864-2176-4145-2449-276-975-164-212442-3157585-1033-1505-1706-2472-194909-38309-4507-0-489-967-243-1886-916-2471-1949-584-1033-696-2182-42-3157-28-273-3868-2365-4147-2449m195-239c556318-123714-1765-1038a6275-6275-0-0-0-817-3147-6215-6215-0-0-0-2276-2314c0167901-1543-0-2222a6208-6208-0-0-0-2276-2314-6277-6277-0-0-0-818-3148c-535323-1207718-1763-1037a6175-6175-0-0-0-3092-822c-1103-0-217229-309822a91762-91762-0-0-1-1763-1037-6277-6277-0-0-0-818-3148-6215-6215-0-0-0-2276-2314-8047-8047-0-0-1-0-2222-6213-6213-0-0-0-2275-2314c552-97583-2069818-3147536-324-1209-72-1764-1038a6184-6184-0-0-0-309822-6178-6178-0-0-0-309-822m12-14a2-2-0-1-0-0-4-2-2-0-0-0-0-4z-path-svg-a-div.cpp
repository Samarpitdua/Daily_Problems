class Solution
{
    public:
        int twoSumLessThanK(vector<int> &nums, int k)
        {
            int n = nums.size(), ans = -1 , sum = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    int sum = nums[i] + nums[j];
                    if (sum < k and ans < sum)
                        ans = sum;
                }
            }
            return ans;
        }
};