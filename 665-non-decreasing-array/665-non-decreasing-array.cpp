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
                if(i == 1)
                {
                    p = 1;
                    continue;
                }
                else
                {
                    if(nums[i] >= nums[i - 2])
                    {
                        nums[i - 1] = nums[i - 2];
                        p = 1;
                        continue;
                    }
                    else
                    {
                        nums[i] = nums[i - 1];
                        p = 1;
                        continue;
                    }
                }
            }
        }
        return true;
    }
};