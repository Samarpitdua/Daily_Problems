class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char , int> mp;
        if(s.size() != t.size())
            return false;
        for(auto x : s)
            mp[x]++;
        for(auto x : t)
        {
            if(mp.find(x) != mp.end())
            {
                mp[x]--;
                if(mp[x] == 0)
                    mp.erase(x);
            }
            else
                return false;
        }
        return (mp.size() == 0);
        // sort(s.begin() , s.end());
        // sort(t.begin() , t.end());
        // return s == t;
    }
};