class Solution {
public:
    int solve(vector<int>& arr , int index , vector<vector<int>>& dp , int ct)
    {
        if(index == 0)
        {
            if(ct * arr[index] > 0)
                return ct * arr[index];
            else
                return 0;
        }
        if(dp[index][ct] != -1)
            return dp[index][ct];
        int take = arr[index] * ct + solve(arr , index - 1 , dp , ct + 1);
        int notTake = 0 + solve(arr , index - 1 , dp , ct);
        return dp[index][ct] = max(take , notTake);
    }
    int maxSatisfaction(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin() , arr.end());
        reverse(arr.begin() , arr.end());
        vector<vector<int>> dp(n , vector<int>(n + 1 , -1));
        return solve(arr , n - 1 , dp , 1);
    }
};