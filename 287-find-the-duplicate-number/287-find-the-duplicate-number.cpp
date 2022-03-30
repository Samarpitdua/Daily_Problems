class Solution {
public:
    //We will use hare and tortoise approach which is very common in linked list 
    int findDuplicate(vector<int>& nums) {
        int i = 0 , slow = 0 , fast = 0;
        while(1)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast)
                break;
        }
        fast = 0;
        while(fast != slow)
        {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};