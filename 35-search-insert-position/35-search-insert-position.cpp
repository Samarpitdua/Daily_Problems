class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int high = n - 1 , low = 0 , ans = -1;
        while(low <= high)
        {
            int mid = (high + low) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        cout<<"i";
        return ans + 1;
        
    }
};