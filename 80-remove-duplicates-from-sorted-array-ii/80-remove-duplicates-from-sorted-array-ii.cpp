class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ct = 1 , n = nums.size();
        if(n <= 2)
            return n;
        int p = 1;
        for(int i = 1 , j = 1; j < n ;)
        {
            if(nums[j] == nums[j - 1] and p == 1)
            {
                nums[i] = nums[j];
                i++;
                j++;
                p = 2;
                ct++;
            }
            else if(nums[j] == nums[j - 1] and p == 2)
            {
                j++;
            }
            else if(nums[j] != nums[j - 1])
            {
                nums[i] = nums[j];
                i++;
                j++;
                p = 1;
                ct++;
            }
        }
       // cout<<ct<<" ";
        return ct;
    }
};