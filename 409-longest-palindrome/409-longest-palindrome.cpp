class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0 , p = -1;
        unordered_map<char , int> mp;
        for(int i = 0 ; i < s.size() ;i++)
        {
            mp[s[i]]++;
        }
        for(auto x : mp)
        {
            if(x.second % 2 == 0)
                ans += x.second;
            else if(p == -1)
                ans += x.second , p = 1;
            else
                ans += (x.second - 1) ;
        }
        return ans;
        
        
    }
};