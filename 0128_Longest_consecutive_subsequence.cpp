class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>mp;
        int ct=0;
        int ans=INT_MIN;
        int h=0;
        for(auto x:nums)mp[x]++;
        for(auto x: mp)
        {
            if(ans==INT_MIN)
            {
                ct++;
                ans=x.first;
                //continue;
            }
            else
            {
                if(x.first==(ans+1))
                    ct++;
                else
                    ct=1;
                ans=x.first;
            }
            //cout<<ct<<" ";
            h=max(h,ct);
        }
        return h;
        
    }
};
