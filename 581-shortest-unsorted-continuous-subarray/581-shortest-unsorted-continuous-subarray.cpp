class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        v = nums;
        sort(nums.begin() , nums.end());
        int start = n , end = -1;
        for(int i = 0 ; i < n ; i++)
        {
            if(nums[i] != v[i])
            {
                start = i;
                break;
            }
        }
        if(start == n)
            return 0;
        
        for(int i = n - 1 ; i >= 0 ; i--)
        {
            if(nums[i] != v[i])
            {
                end = i;
                break;
            }
        }
        return abs(end - start + 1);
    }
};