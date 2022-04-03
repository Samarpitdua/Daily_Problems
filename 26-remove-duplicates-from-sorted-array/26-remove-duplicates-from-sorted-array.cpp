class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ct = 1 , n = nums.size();
        for(int i = 1 , j = 1; j < n ;)
        {
            if(nums[j] == nums[j - 1])
                j++;
            else
            {
                nums[i] = nums[j];
                j++;
                i++;
                ct++;
            }
        }
        cout<<ct<<" ";
        return ct;
    }
};