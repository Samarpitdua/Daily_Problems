class Solution {
public:
int solve(vector<string>& strs , int m , int n , vector<vector<vector<int>>>& dp , int index)
{
    
    if(m == 0 and n == 0)
        return 0;
    
    if(index == 0)
    {
        int z = count(strs[index].begin() , strs[index].end() , '0');
        int o = strs[index].size() - z;
        if( (m - z) >= 0 and (n - o) >= 0)
            return 1;
        else
            return 0;
    }
    
    if(dp[index][m][n] != -1)
        return dp[index][m][n];
    
    int z = count(strs[index].begin() , strs[index].end() , '0');
        int o = strs[index].size() - z;
    
        int take = INT_MIN;
        if((m - z) >= 0 && (n - o) >= 0)
            take = 1 + solve(strs , m - z, n - o, dp , index - 1);
        int notTake = solve(strs , m , n , dp , index - 1);
        return dp[index][m][n] = max(take , notTake);
    
}
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vector<vector<vector<int>>> dp(sz + 1, vector<vector<int>>(m + 1 , vector<int>(n + 1 , -1)));
        return solve(strs , m , n , dp , sz - 1);
    }
};
