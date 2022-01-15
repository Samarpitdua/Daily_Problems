class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        long long int n = nums.size() ;
        if(nums.size() < 3)
            return false;
        long long int mini1 = INT_MAX , mini2 = 21474836472;
        
        for(int i = 0 ; i < n;i++)
        {
            if(nums[i] > mini1 and nums[i] > mini2)
                return true;
            else if(nums[i] <= mini1)
            {
                mini1 = nums[i];
            }
            else if(nums[i] <= mini2)
                mini2 = nums[i];
            
        }
        // cout<<"\n";
        return false;
        
    }
};