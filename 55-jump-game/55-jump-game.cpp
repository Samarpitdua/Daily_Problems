class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        for(int i = 1 ; i < n ; i++)
        {
            
            if(maxi >= n - 1)
                return true;
            if(i <= maxi)
            {
                maxi = max(maxi , nums[i] + i);
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};