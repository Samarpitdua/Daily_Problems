class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size();
        int ct = 1;
    vector<vector<long long int>>dp(n , vector<long long int>(m , 0));
    for(int i = 0 ; i < m ;i++)
    {
        if(mat[0][i] == 1)
            ct = 0;
        dp[0][i] = ct;
    }
    ct = 1;
    for(int i = 0 ; i < n ; i++)
    {
        if(mat[i][0] == 1)
            ct = 0;
        dp[i][0] = ct;
    }
    for(int i = 1 ; i < n ; i++)
    {
        for(int j = 1 ; j < m ; j++)
        {
            if(mat[i][j] == 1)
            {
                dp[i][j] = 0;
                continue;
            }
            int ct1 = dp[i - 1][j];
            int ct2 = dp[i][j - 1];
            if(dp[i - 1][j] == -1)
                ct1 = 0;
            if(dp[i][j - 1] == -1)
                ct2 = 0;
            dp[i][j] = (ct1 + ct2) ;
        }
    }
    return dp[n - 1][m - 1];
    }
};