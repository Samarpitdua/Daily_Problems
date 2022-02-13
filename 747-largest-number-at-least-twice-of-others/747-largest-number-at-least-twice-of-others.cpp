class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();
        int p = *max_element(nums.begin() , nums.end());
        int ans = -1 , ct = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(nums[i] == p)
                ct++ , ans = i;
            else
            {
                if(nums[i ] * 2 <= p)
                    continue;
                else
                    return -1;
            }
        }
        if(ct > 1)
            return -1;
        else
            return ans;
        
    }
};