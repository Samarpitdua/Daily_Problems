class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        for(int left = 0 , mid = left + 1 , right = n - 1 ; left <= right and mid <= right;)
        {
            if(nums[left] == 0)
                left++ , mid++;
            else if(nums[right] == 2)
                right-- ;
            else if(nums[left] == 2)
                swap(nums[left] , nums[right]) , right--;
            else if(nums[right] == 0)
                swap(nums[left] , nums[right]) , left++ , mid++;
            else
            {
                if(nums[mid] < nums[left])
                    swap(nums[mid] , nums[left]) , mid++ , left++;
                else if(nums[mid] > nums[right])
                    swap(nums[mid] , nums[right]) , right--;
                else
                    mid++;
            }
            
            
        }
    }
};