class Solution {
public:
    int minSubArrayLen(int target, vector<int>& a) {
        int sum=0,ans=INT_MAX;
        int n=a.size(),ct=0;
        for(int i=0,j=0;i<n and j<n;)
        {
            ct++;
            sum+=a[j];
            while(sum>=target)
            {
                ans=min(ans,j-i+1);
                cout<<ct<<" "<<ans<<" ";
                if(ans==1)
                    return 1;
                else sum-=a[i], i++;
            }
            
            {
                j++;
            }
            
        }
        if(ans==INT_MAX) return 0;
            return ans;
    }
};