class Solution {
public:
    // Just check floor points and consider array as circular array
    bool check(vector<int>& nums) {
        int n = nums.size() , p = 0;
        if(n == 1)
            return true;
        for(int i = 0 ; i < n - 1 ; i++)
        {
            if(nums[i+1] >= nums[i])
                continue;
            else
                p++;
        }
        if(nums[n - 1] > nums[0])
            p++;
        return (p<2);
        
    }
};