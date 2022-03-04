class Solution {
public:
    double dp[102][102];
    // vector<vector<double>> dp(102 , vector<double>(102 , -1));
    double solve(int poured, int row, int glass)
    {
        
        if((row < 0) or (glass < 0) or (glass > row))
            return 0.00;
        
        if(row == 0 and glass == 0)
            return poured;
        
        
        if(dp[row][glass] > -1)
            return dp[row][glass];
        
        double left = (solve(poured , row - 1 , glass - 1) - 1) / 2;
        
        if(left < 0)
            left = 0;
        
        double right = (solve(poured , row - 1 , glass) - 1) / 2;
        
        if(right < 0)
            right = 0;
        
        double ans = left + right;
        return dp[row][glass] = ans;
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        memset(dp, -1, sizeof(dp));
        return min(1.0 , solve(poured , query_row , query_glass));
    }
};