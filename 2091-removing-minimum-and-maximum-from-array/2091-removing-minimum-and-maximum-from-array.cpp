class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini = nums[0] , maxi = nums[0] , n = nums.size();
        if(n == 1)
            return 1;
            
        int m1 = 0 , n1 = 0;
        for(int i = 1; i  < nums.size() ; i++){
            if(mini > nums[i])
            {
                mini = nums[i];
                m1 = i;
            }
            if(maxi < nums[i])
                maxi = nums[i] , n1 = i;
        }
        int ans;
        if(n1 > m1)
            swap(n1 , m1);
        
        ans = min({m1 + 1 , n - n1 , n1 + 1 + n - m1});
        return ans;
    }
};