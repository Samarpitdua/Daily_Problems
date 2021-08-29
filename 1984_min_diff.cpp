class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0,j=0;j<n;)
        {
            if(j<k-1)
                j++;
            else
            {
               int ans1=nums[i];
                int ans2=nums[j];
               int diff=ans2-ans1;
                if(diff<ans)
                    ans=diff;
                i++,j++;
            }
        }
        return ans;
        
    }
};
