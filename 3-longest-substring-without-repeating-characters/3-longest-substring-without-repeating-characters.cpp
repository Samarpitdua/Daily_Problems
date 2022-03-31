class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char , int> mp;
        int ct = 0 , ans = 0;
        for(int i = 0 , j = 0; i < s.size() ;)
        {
            if(mp[s[i]] == 0)
            {
                mp[s[i]]++;
                i++;
            }
            else
            {
                mp[s[j]]--;
                j++;
            }
            ans = max(ans , i - j);
        }
        
        return ans;
    }
};