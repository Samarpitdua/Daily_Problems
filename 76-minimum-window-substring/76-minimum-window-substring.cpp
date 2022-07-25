class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> mp(128 , 0);
        // unordered_map<char , int> mp;
        for(auto x : t)
            mp[x]++;
        
        long long int l = 0 , r = 0 , ct = t.size() , m = s.size() , mini = 0 , maxi = INT_MAX;
        while(r < m)
        {
            if(mp[s[r]] > 0)
                ct--;
            // cout<<ct<<" ";
            mp[s[r]]--;
            r++;
            while(ct == 0)
            {
                if((r - l) < maxi)
                {
                    maxi = r - l;
                    mini = l;
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0)
                    ct++;
                l++;
            }
        }
        if(maxi == INT_MAX)
            return "";
        // cout<<maxi<<" "<<mini;
        return s.substr(mini , maxi);
        
    }
};