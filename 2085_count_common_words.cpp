class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        int n = words1.size();
        int m = words2.size();
        int ct = 0;
        map<string,int>mp,mp1,mp2;
        for(int i = 0;i < n;i++)
        {
            mp1[words1[i]]++;
        }
        for(int i = 0;i < m;i++)
        {
            mp2[words2[i]]++;
        }
        for(auto x:mp1)
        {
            if(x.second==1)
                mp[x.first]++;
        }
        for(auto x:mp2)
        {
            if(x.second == 1 and mp[x.first])
                ct++;
        }
        return ct;
        
    }
};
