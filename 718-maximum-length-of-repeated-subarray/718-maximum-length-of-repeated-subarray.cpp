class Solution {
public:
    //Just like longest common substring
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ct = 0;
        int n1 = nums1.size() , n2 = nums2.size();  
        vector<vector<int>> dp(n1 + 1 , vector<int>(n2 + 1 , 0));
        for(int i = 1 ; i <= n1 ; i++)
        {
            for(int j = 1 ; j <= n2 ; j++)
            {
                if(nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                ct = max(ct , dp[i][j]);
            }
        }
        return ct;
    }
};