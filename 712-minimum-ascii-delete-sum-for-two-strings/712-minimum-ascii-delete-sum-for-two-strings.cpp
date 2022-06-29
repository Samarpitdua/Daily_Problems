class Solution {
public:
   
    int minimumDeleteSum(string s, string t) {
         int m = s.size() , n = t.size();
        vector<vector<int>> dp (m + 1 , vector<int> (n + 1 , 0));
         for(int i = 1 ;i <= m ;i++)
        {
            for(int j = 1 ;j <= n;j++)
            {
                if(s[i - 1] == t[j - 1])
                    dp[i][j] = s[i - 1] + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
            }
        }
        int ans = 0;
        for(int i =0 ; i < m;i++)
        {
            ans += s[i];
        }
        for(int j =0 ; j < n;j++)
        {
            ans += t[j];
        }
        ans -= 2* dp[m][n];
        return ans;
        
    }
};
    