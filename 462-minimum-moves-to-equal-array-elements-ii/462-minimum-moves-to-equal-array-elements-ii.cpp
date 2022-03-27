class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size() , sum = 0 , ans = 0;
        sort(nums.begin() , nums.end());
        for(int i = 0 , j = n - 1 ; i <= j ; i++ , j--)
        {
            ans += abs(nums[i] - nums[j]);
        }
        return ans;
        
    }
};