class Solution {
public:
    //See copy for more explanation
    int countSubstrings(string s) {
        int n = s.size();
        int ct = 0;
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int gap = 0; gap < n; gap++)
        {
            for(int i = 0, j = gap; j < n ; i++, j++)
            {
                if(gap == 0)
                    dp[i][j] = true;
                else if(gap == 1)
                {
                    if(s[i] == s[j])
                        dp[i][j] = true;
                    else
                        dp[i][j] = false;
                }
                else
                {
                    if(s[i] == s[j] and dp[i+1][j-1] == true)
                        dp[i][j] = true;
                }
                if(dp[i][j])
                    ct++;
            }
        }
        return ct;
    }
};