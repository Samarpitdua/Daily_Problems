class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        if(nums.size()<4)
            return ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int target_2=target-nums[i]-nums[j];
                int start=j+1,end=n-1;
                while(start<end)
                {
                    int sum=nums[start]+nums[end];
                    if(sum<target_2)start++;
                    else if (sum>target_2)end--;
                    else
                    {
                        vector<int>res(4);
                        res[0]=nums[i];
                        res[1]=nums[j];
                        res[2]=nums[start];
                        res[3]=nums[end];
                        ans.push_back(res);
                        
                        while(start<end and nums[start]==res[2])
                        {
                            start++;
                        }
                        while(start<end  and nums[end]==res[3])
                        {
                            end--;
                        }
                    }
                }
                while(j+1<n and nums[j+1]==nums[j])j++;
            }
            while(i+1<n and nums[i]==nums[i+1])i++;
        }
        return ans;
    }
};
