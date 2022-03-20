class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> v;
        int n = nums.size() , ct = 0;
        for(int i = 0 ; i < n - 1 ; i++)
        {
            if(nums[i] == nums[i + 1])
                continue;
            else
                v.push_back(nums[i]);
        }
        v.push_back(nums[n - 1]);
        
        for(int i = 1 ; i < (v.size() - 1) ; i++)
        {
            if((v[i] > v[i - 1] and v[i] > v[i + 1]) or (v[i] < v[i - 1] and v[i] < v[i + 1]))
                ct++;
        }
        return ct;
    }
};