class Solution {
public:
    //We will use hare and tortoise approach which is very common in linked list 
    int findDuplicate(vector<int>& nums) {
        int i=0;
        int fast=nums[0],slow=nums[0];
        while(1)
        {
            fast=nums[nums[fast]];
            slow=nums[slow];
            if(fast==slow)
                break;
        }
        fast=nums[0];
        while(fast!=slow)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};
