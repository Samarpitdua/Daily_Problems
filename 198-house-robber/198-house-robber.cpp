class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int a = nums[0] ; 
        if(n == 1)
            return a;
        int b = max(nums[0] , nums[1]) , c = b;
        for(int i = 2 ; i < n ;i++)
        {
            c = max(b , a + nums[i]);
            a = b;
            b = c;
        }
        return c;
            
    }
};