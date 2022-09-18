class Solution {
public:
    int longestContinuousSubstring(string s) {
        vector<int> v;
        int ans = 1 , ct = 1;
        for(int i = 0 ; i < s.size() - 1 ;i++)
        {
            if(s[i] + 1 == s[i + 1])
            {
                ct++;
            }
            else
                ct = 1;
            ans = max(ans , ct);
        }
        return ans;
    }
};