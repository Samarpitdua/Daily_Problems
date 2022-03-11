class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int>mp;
        int ans=0;
        int ct=0;
        for(int i=0;i<words.size();i++)
        {
            int p=0;
            string t=words[i];
            reverse(t.begin(),t.end());
            if(words[i][0] == words[i][1])
                ct++,p=1;
            
             if(mp[t]>0)
            {
                 if(p==1)
                     ct-=2;
                ans+=4;
                mp[t]--;
            }
            else
                mp[words[i]]++;
        }
        if(ct>0)
            ans+=2;
        return ans;
    }
};