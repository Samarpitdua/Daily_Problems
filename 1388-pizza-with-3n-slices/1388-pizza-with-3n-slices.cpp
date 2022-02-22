class Solution {
public:
    int solve(vector<int>& slices , int n , vector<vector<int>>& dp , int ct , int index)
    {
        if(ct == n/3 or index < 0)
            return 0;
        if(dp[index][ct] != -1)
            return dp[index][ct];
        int take = slices[index] + solve(slices , n , dp , ct + 1, index - 2);
        int notTake = solve(slices , n , dp , ct , index - 1);
        return dp[index][ct] = max(take , notTake);
    }
    
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        vector<vector<int>> dp(n + 1 , vector<int> (n /3 + 1 , -1));
        vector<vector<int>> dp2(n + 1 , vector<int> (n /3 + 1 , -1));
        
        vector<int> a(slices.begin() , slices.end() - 1);
        vector<int> b(slices.begin() + 1 , slices.end() );
        
        int ans = max(solve(a , n  , dp , 0 , n - 2) , solve(b , n, dp2 , 0 , n - 2));
        return ans;
        
    }
};