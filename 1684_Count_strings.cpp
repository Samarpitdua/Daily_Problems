class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        map<char,int>mp;
        for(int i=0;i<allowed.size();i++)
            mp[allowed[i]]++;
        int f=0,ct=0;
        for(auto x:words)
        {
            f=0;
            for(auto y:x)
            {
                if(mp[y]==0)
                {
                    f=1;
                    break;
                }
            }
            if(f==1)
                continue;
            else
                ct++;
        }
        return ct;
        
    }
};
