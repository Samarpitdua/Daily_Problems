class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ct = 1 , temp = nums[0];
        int n = nums.size();
        for(int i = 1 ; i < n ; i++ )
        {
            if(temp == nums[i])
                ct++;
            else
            {
                if(ct == 0)
                {
                    ct = 1;
                    temp = nums[i];
                }
                else
                    ct--;
            }
        }
        return temp;
    }
    
};