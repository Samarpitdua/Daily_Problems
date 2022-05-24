class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int low = 0 , high = 1000 , n = nums.size();
        while(low <= high)
        {
            int temp = lower_bound(nums.begin() , nums.end() , low) - nums.begin();
            if(n - temp == low)
                return low;
            else
                low++;
        }
        return -1;
    }
};