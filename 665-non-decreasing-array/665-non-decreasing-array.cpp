class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int p = 0;
        for(int i = 1 ; i < nums.size() ;i++)
        {
            if(nums[i] >= nums[i - 1])
                continue;
            else
            {
                if(p == 1)
                    return false;
                p = 1;
                if(i == 1)
                {
                    
                }
                else
                {
                    if(nums[i] >= nums[i - 2])
                    {
                 
                    }
                    else
                    {
                        nums[i] = nums[i - 1];
                    }
                }
            }
        }
        return true;
    }
};