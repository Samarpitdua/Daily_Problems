class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char , char> mp;
        map<char , int> mp2;
        for(int i = 0 ; i < s.size() ;i++)
        {
            if(mp.find(s[i]) != mp.end())
               {
                   if(mp[s[i]] != t[i])
                       return false;
               }
            else if(mp2[t[i]])
                return false;
             else
               {
                   mp[s[i]] = t[i];
                   mp2[t[i]]++;
               }
        }
        return true;
        
    }
};