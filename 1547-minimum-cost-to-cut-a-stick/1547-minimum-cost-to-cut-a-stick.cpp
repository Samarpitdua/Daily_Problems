class Solution {
public:
    int solve(vector<int>& cuts , vector<vector<int>>& dp , int i , int j)
    {
        if(i > j)
        {
            return 0;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = INT_MAX;
        for(int ind = i ; ind <= j ; ind++)
        {
            ans = min(ans , (cuts[j + 1] - cuts[i - 1]) + solve(cuts , dp , i , ind - 1) + solve(cuts , dp , ind + 1 , j));
        }
        return dp[i][j] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin() , cuts.end());
        int y = cuts.size();
        vector<vector<int>> dp(y , vector<int>(y , -1));
        return solve(cuts , dp , 1 , cuts.size() - 2);
    }
};