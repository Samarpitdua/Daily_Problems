class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size() , sum = 0 , ans = -1;
        vector<int> preSum(n , 0);
        for(int i = 0 ; i < n ;i++)
        {
            preSum[i] = sum;
            sum += nums[i];
        }
        sum = 0;
        for(int j = n - 1 ; j >= 0 ;j--)
        {
            if(sum == preSum[j])
                ans = j;
            sum += nums[j];
        }
        return ans;
    }
};