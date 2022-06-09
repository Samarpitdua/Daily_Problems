class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0,j=nums.size()-1;i<nums.size();)
        {
            if(nums[i]+nums[j]==target)
            {
                vector<int>v;
                v.push_back(i+1);
                v.push_back(j+1);
                return v;
            }
            else if(nums[i]+nums[j]>target)j--;
            else i++;
        }
        vector<int>v;
        return v;
    }
};