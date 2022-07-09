class Solution {
public:
    int solve(vector<int>& nums , int i , vector<int>& dp , int n){
        if(i >= n){
            return 10000;
        }
        if(i == n - 1)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int ans = 10000;
        for(int j = 1 ; j <= nums[i] and (i + j) < n ;j++){
            ans = min(ans , 1 + solve(nums , i + j , dp , n));
        }
        return dp[i] = ans;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1 , -1);
        return solve(nums , 0 , dp , n);
    }
};