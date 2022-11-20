class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int n = nums.size() , ct = 0;
        for(int i = 0 ;  i < n - 2;i++){
            for(int j = i + 1 ; j  < n - 1;j++){
                for(int k = j + 1 ; k < n ;k++){
                    if(nums[i] != nums[j] and nums[i] != nums[k] and nums[j] != nums[k])
                        ct++;
                }
            }
        }
        return ct;
    }
};