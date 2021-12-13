class Solution {
public:
    int maxPower(string s) {
        int ct = 1,n = s.size(),ans = 1;
        for(int i = 0;i<n-1;i++)
        {
            if(s[i] == s[i+1])
                ct++;
            else
                ct = 1;
            ans = max(ans,ct);
           // cout<<ct<<" ";
        }
        return ans;
        
        
    }
};
