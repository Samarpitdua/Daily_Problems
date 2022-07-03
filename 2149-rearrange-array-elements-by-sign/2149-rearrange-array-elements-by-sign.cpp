class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int i = 0 , j = 0 ;i < n  and  j < n ;)
        {
            while(nums[j] > 0)
                j++;
            while(nums[i] < 0)
                i++;
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            i++ , j++ ;
        }
        return ans;
        
    }
};