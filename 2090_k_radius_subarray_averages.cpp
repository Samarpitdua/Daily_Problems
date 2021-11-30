class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
       long long int n = nums.size();
        vector<int>ans;
        long long int sum=0,avg;
        int q=-1;
        for(int i=0,p=k;i<n;i++)
        {
            if(p>=n)
            {
                ans.push_back(-1);
                p++;
                continue;
            }
            if(i<k)
            {
                ans.push_back(-1);
                sum+=nums[i];
                p++;
                sum+=nums[p];
            }
            else
            {
                if(q==-1)
                q=1,sum+=nums[i];
                
                avg=sum/(k*2+1);
             //   cout<<"\n"<<avg<<" ";
                ans.push_back(avg);
                sum-=nums[i-k];
                p++;
                if(p<n)
                sum+=nums[p];
                
            }
           // cout<<sum<<" ";
        }
        return ans;
    }
};
