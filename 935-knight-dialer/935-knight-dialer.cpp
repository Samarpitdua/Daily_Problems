#define MOD 1000000007
class Solution {
public:
    int knightDialer(int n) {
        if(n == 1)
            return 10;
        vector<vector<long long int>> dp(n + 1, vector<long long int>(10 , 0));
        for(int i = 0 ; i <= 9 ;i++)
        {
            dp[1][i] = 1;
        }
        for(int i = 2 ;i <= n ;i++)
        {
            dp[i][0] = dp[i - 1][4] + dp[i - 1][6];
            dp[i][1] = dp[i - 1][8] + dp[i - 1][6];
            dp[i][2] = dp[i - 1][7] + dp[i - 1][9];
            dp[i][3] = dp[i - 1][8] + dp[i - 1][4];
            dp[i][4] = dp[i - 1][3] + dp[i - 1][9] + dp[i - 1][0];
            dp[i][6] = dp[i - 1][7] + dp[i - 1][0] + dp[i - 1][1];
            dp[i][7] = dp[i - 1][2] + dp[i - 1][6];
            dp[i][8] = dp[i - 1][1] + dp[i - 1][3];
            dp[i][9] = dp[i - 1][4] + dp[i - 1][2];
            for(int j = 0 ;j <= 9 ;j++)
                dp[i][j]%=MOD;
        }
        int ans = 0;
        for(int i = 0;i <= 9;i++)
        {
            ans += dp[n][i];
            ans %= MOD;
        }
        return ans;
    }
};