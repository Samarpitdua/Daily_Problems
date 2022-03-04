class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2 , int i , int j , vector<vector<int>>& dp)
    {
        if(i < 0 or j < 0)
            return 0;
        if(dp[i][j] != -10e7)
            return dp[i][j];
        int a = 0;
        if(nums1[i] == nums2[j])
            a = 1 + solve(nums1 , nums2 , i - 1 , j - 1 , dp);
        int b = solve(nums1 , nums2 , i , j - 1 , dp);
        int c = solve(nums1 , nums2 , i - 1 , j , dp);
        int d = solve(nums1 , nums2 , i - 1 , j - 1 , dp);
        return dp[i][j] = max({a , b , c , d});
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> dp(n1 + 1 , vector<int>(n2 + 1 , -10e7));
        int ans = 0;
         ans = solve(nums1 , nums2 , n1 - 1 , n2 - 1, dp);
        return ans;
    }
};