class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long int n=nums.size();
        vector<long long int>lsum(n,0),rsum(n,0);
        long long int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            lsum[i]=sum/(i+1);
        }
        long long int ct=1;
        sum = nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            
            rsum[i]=sum/ct;
         //   cout<<rsum[i]<<" ";
            ct++;
            sum+=nums[i];
        }
        long long int ans = INT_MAX ;int ans2 = 0;
        for(int i = 0 ;i < n ;i++)
        {
            // cout<<lsum[i]<<" "<<rsum[i]<<endl;
            long long int temp = abs(lsum[i] - rsum[i]);
            if(temp < ans)
            {
                ans= temp;
                ans2 = i;
            }
        }
        return ans2;
        
    }
};