class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        int sum2=n*(n+1)/2;
        return (sum2-sum);
    }
};