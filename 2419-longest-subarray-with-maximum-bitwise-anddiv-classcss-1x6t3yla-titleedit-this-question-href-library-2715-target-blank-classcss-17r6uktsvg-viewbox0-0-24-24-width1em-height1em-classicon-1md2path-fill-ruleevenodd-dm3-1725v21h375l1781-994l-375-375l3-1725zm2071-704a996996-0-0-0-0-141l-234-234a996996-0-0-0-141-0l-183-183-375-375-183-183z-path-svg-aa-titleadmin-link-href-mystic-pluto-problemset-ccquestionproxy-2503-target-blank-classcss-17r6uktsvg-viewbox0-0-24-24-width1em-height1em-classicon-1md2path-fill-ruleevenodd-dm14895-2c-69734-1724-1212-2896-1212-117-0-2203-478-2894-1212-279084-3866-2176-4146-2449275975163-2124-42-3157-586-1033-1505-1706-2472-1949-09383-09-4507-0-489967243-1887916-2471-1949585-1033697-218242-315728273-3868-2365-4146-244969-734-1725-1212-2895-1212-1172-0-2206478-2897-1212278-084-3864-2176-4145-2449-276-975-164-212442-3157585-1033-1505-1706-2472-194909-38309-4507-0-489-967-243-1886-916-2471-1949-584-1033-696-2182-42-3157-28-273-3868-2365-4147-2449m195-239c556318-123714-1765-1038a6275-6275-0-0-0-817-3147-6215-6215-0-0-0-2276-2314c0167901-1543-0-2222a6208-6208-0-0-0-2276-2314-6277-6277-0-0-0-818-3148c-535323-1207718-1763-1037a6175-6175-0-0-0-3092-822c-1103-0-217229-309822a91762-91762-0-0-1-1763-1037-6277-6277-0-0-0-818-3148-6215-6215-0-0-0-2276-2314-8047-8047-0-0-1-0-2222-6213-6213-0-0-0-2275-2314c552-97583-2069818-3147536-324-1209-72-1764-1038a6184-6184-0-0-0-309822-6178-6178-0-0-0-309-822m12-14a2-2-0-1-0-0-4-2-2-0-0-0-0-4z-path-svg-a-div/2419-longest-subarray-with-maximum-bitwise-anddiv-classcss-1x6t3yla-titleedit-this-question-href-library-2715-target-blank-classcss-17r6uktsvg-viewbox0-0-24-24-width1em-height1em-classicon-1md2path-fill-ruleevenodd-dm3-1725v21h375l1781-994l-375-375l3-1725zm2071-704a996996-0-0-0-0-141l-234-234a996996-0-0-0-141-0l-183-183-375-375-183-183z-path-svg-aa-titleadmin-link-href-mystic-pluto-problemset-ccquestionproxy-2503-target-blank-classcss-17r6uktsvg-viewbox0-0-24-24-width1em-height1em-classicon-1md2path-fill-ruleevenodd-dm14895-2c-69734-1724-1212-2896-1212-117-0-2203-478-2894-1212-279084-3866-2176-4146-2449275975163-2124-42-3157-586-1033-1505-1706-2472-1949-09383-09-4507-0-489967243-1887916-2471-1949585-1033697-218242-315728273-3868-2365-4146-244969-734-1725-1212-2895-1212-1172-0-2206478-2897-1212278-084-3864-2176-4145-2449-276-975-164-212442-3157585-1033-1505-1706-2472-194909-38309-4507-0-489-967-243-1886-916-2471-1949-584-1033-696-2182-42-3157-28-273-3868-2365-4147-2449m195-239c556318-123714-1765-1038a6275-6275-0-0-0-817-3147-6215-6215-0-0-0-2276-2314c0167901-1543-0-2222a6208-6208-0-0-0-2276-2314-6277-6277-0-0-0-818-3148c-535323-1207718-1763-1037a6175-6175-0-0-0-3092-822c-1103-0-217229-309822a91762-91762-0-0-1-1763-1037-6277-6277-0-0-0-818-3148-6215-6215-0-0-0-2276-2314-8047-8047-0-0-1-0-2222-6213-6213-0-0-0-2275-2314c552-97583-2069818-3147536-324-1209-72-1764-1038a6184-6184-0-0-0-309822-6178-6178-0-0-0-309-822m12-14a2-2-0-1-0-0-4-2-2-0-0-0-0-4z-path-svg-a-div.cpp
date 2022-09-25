class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin() , nums.end()) , ans = 0 , ct = 0;
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] == maxi)
            {
                ct++;
            }
            else
                ct = 0;
            ans = max(ans , ct);
        
        }
        return ans;
    }
};