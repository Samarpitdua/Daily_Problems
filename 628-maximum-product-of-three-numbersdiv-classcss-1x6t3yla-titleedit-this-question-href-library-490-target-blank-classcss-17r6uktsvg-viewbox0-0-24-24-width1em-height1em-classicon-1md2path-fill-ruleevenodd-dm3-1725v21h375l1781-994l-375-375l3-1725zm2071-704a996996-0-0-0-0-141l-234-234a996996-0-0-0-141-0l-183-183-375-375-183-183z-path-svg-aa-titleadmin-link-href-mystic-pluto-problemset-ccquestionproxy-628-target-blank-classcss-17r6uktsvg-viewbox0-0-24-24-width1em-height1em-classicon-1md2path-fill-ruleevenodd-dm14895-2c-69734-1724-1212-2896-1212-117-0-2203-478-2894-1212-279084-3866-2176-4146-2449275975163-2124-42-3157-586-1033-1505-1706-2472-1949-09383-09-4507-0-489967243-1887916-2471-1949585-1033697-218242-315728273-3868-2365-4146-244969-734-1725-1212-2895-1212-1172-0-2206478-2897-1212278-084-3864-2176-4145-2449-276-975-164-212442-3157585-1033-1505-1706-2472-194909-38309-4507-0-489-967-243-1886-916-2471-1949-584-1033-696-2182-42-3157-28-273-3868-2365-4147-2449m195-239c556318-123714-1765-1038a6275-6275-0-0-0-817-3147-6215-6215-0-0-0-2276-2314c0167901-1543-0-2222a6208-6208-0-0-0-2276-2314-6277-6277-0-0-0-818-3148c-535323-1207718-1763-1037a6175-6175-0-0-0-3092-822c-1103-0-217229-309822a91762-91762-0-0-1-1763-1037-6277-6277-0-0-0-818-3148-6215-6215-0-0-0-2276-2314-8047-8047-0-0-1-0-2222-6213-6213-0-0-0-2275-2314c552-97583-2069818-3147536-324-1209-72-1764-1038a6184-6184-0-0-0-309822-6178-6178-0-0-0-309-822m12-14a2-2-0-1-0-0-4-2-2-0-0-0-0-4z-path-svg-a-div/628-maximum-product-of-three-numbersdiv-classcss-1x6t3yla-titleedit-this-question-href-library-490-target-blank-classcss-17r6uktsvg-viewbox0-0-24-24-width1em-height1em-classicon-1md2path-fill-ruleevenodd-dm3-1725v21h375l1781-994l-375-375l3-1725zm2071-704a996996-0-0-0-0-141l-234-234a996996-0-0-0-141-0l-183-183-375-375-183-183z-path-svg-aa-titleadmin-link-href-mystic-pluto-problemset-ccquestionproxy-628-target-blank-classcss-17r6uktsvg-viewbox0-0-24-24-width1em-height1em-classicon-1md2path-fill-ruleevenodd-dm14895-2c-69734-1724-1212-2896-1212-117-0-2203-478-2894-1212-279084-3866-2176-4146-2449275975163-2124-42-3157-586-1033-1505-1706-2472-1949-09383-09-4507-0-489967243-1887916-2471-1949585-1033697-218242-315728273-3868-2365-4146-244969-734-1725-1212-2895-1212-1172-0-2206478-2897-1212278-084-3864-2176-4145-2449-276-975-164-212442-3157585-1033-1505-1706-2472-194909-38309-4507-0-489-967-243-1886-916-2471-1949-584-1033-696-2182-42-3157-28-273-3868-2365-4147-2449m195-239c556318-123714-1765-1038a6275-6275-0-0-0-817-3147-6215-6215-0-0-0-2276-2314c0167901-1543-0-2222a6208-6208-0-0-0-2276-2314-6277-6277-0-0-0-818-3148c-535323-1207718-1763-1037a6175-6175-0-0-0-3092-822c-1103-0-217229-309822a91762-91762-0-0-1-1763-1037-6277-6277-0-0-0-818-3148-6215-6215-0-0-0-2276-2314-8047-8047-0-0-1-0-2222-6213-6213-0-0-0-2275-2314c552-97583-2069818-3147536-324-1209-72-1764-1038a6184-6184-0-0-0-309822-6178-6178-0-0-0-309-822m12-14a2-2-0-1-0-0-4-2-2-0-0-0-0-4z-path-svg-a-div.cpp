class Solution
{
    public:
        int maximumProduct(vector<int> &nums)
        {
            int n = nums.size();
            sort(nums.begin(), nums.end());
            int ct = 0, p = INT_MIN;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == 0)
                    ct++;
            }
            if (ct)
                p = 0;
            return max({ nums[n - 1] *nums[n - 2] *nums[n - 3],
                nums[0] *nums[1] *nums[n - 1],
                p });
        }
};