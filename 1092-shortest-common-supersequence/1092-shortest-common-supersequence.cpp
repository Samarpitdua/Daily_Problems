class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        
        int n = s.size() , m = t.size();
        vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , 0));
        
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= m ;j++)
            {
                if(s[i - 1] == t[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
            }
        }
        int i = n , j = m;
        string ans="";
        while(i > 0 && j > 0)
        {
            if(s[i - 1] == t[j - 1])
            {
                ans.push_back(s[i - 1]);
                i--;
                j--;
            }
            else if(dp[i][j - 1] > dp[i - 1][j])
            {
                ans.push_back(t[j - 1]);
                j--;
            }
            else
            {
                ans.push_back(s[i - 1]);
                i--;    
            }
                
        }
        while(i > 0)
        {
            ans.push_back(s[i - 1]);
            i--;
        }
        while(j > 0)
        {
            ans.push_back(t[j - 1]);
            j--;
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};