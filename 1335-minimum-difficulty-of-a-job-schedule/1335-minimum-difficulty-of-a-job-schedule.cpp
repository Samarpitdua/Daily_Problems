class Solution {
public:
    int minDifficulty(vector<int>& jd, int d) {
        int n = jd.size();
        if(n < d)
            return -1;
        
        vector<vector<int>> dp(n , vector<int> (d,1e9));
        dp[0][0] = jd[0];
        for(int i=1;i<n;i++)
        {
            dp[i][0]=max(dp[i-1][0] , jd[i]);
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<min(i+1,d);j++)
            {
                int maxd=0;
                for(int k=i-1;k>=0;k--)
                {
                    maxd=max(maxd,jd[k+1]);
                    dp[i][j] = min(dp[i][j], dp[k][j-1]+ maxd);
                }
            }
        }
        return dp[n-1][d-1];
    }
};