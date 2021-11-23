class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>mp;
        int ans=0;
        for(int i=0,j=0;j<s.size();)
        {      
            if(mp[s[j]]>0)
            {
                mp[s[i]]--;
                i++;
                continue;
            }
            mp[s[j]]++;
             ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
