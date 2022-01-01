class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size() , sum = 0 ;
        vector<int> left(n) , right(n) ;
        for(int i = 0 ; i < n ; i++)
        {
            left[i] = sum;
            sum += nums[i];
        }
        
        sum = 0;
        for(int i = n - 1 ; i >= 0 ; i--)
        {
            right[i] = sum;
            sum += nums[i];
        }
        for(int i = 0 ; i < n ; i++)
            if(left[i] == right[i])
                return i;
        return -1;
    }
};