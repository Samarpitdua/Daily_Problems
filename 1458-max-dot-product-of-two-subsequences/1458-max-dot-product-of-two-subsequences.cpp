class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2 , int i , int j , vector<vector<int>>& dp)
    {
        if(i < 0 or j < 0)
            return 0;
        if(dp[i][j] != -10e7)
            return dp[i][j];
        int a = nums1[i] * nums2[j] + solve(nums1 , nums2 , i - 1 , j - 1 , dp);
        int b = solve(nums1 , nums2 , i , j - 1 , dp);
        int c = solve(nums1 , nums2 , i - 1 , j , dp);
        int d = solve(nums1 , nums2 , i - 1 , j - 1 , dp);
        return dp[i][j] = max({a , b , c , d});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> dp(n1 + 1 , vector<int>(n2 + 1 , -10e7));
        int ans = 0;
         ans = solve(nums1 , nums2 , n1 - 1 , n2 - 1, dp);
        if(ans == 0)
        {
            if (count(nums1.begin(), nums1.end(), 0) or count(nums2.begin(), nums2.end(), 0))
                return 0;
            int maxi1 = *max_element(nums1.begin() , nums1.end());
            int maxi2 = *max_element(nums2.begin() , nums2.end());
            int mini1 = *min_element(nums1.begin() , nums1.end());
            int mini2 = *min_element(nums2.begin() , nums2.end());
            
            return max(maxi1 * mini2 , maxi2 * mini1);
        }
        return ans;
    }
};