class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
     //   vector<vector<int>>dp(n,vector<int>(p,-1));
        dp[n][m]=1;
        for(int i=n;i>=0;i--)
        {
            for(int j=m;j>=0;j--)
            {
                if(i==n and j==m)
                    dp[i][j]=1;
                else if(j==m)
                    dp[i][j]=0;
                else if(i==n)
                {
                    if(p[j]=='*')
                        dp[i][j]=dp[i][j+1];
                    else
                        dp[i][j]=0;
                }
                
                else if(p[j]=='?')
                {
                    dp[i][j]=dp[i+1][j+1];
                }
                else if(p[j]=='*')
                {
                    dp[i][j]=(dp[i+1][j] || dp[i][j+1]);
                }
                else if(s[i]==p[j])
                    dp[i][j]=dp[i+1][j+1];
                else
                    dp[i][j]=0;
            }
        }
        return dp[0][0];
    }
};
