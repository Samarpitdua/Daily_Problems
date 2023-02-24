class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size() , low = 0 , high = n - 1 ;
        if(n == 1)
            return 0;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            
            if(mid == 0)
            {
                if(nums[mid] > nums[mid + 1])
                    return mid;
                else
                    low = mid + 1;
            }
            else if(mid == (n - 1))
            {
                if(nums[mid] > nums[mid - 1])
                    return mid;
                else
                    high = mid - 1;
            }
            else
            {
                if(nums[mid] > nums[mid - 1] and nums[mid] > nums[mid + 1])
                    return mid;
                
                else if(nums[mid - 1] > nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
                    
            }
        }
       
        return -1;
    }
};