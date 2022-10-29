class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ct = 0 , ans = 0 , p = 0;
        for(int i = 0 , j = 0; i < nums.size() and j < nums.size(); j++){
            if(nums[j] == 1)
            {
                ct++;
            }
            else if(nums[j] == 0 and p == 0)
            {
                ct++;
                p++;
            }
            else if(nums[j] == 0 and p == 1)
            {
                while(p != 0)
                {
                    if(nums[i] == 0)
                        p--;
                    i++;
                }
                ct++;
                p++;
            }
            ans = max(ans , j - i + 1);
        }
        return ans;
    }
};