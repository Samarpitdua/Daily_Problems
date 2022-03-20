class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int sum = 0 , ct = 0;
        vector<int> ans;
        for(auto x : nums)
            sum += x;
        sort(nums.begin() , nums.end() , greater<int>());
        if(sum % 2)
            sum = (sum + 1)/ 2 ;
        else
            sum = (sum / 2) + 1;
        for(auto x : nums)
        {
            ct += x;
            ans.push_back(x);
            if(ct >= sum)
                return ans;
        }
        return ans;
        
    }
};