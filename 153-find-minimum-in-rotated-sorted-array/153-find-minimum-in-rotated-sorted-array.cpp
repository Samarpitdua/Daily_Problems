class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size() , l = 0 , r = n - 1;
        if(n == 1)
            return nums[0];
        while(l < r)
        {
            int mid = l + (r - l) / 2;
            if(mid > 0 and nums[mid] < nums[mid - 1])
            {
                return nums[mid];
            }
            else if(nums[mid] >= nums[l] and nums[mid] > nums[r])
                l = mid + 1;
            else
                r = mid - 1;
        }
        return nums[l];
    }
};