class Solution {
public:
    int solve(vector<int>& arr , int i , int n , vector<int>& dp , int mid)
    {
        if(i >= n)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int maxi = INT_MIN , ans = INT_MIN;
        int ct = 0;
        for(int k = i ; k < min(n , mid + i) ; k++)
        {
            ct++;
            maxi = max(maxi , arr[k]);
            ans = max(ans , maxi * (ct) + solve(arr , k + 1 , n , dp ,mid));
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1 , -1);
        return solve(arr , 0 , n , dp , k);
    }
};