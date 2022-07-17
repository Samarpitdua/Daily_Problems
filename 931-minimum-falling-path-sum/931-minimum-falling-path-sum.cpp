class Solution {
public:
    int solve(int n , int i , int j , vector<vector<int>>& mat , vector<vector<int>>& dp){
        
        if(j >= n or j < 0)
            return 1e8;
        if(i == n - 1){
            return mat[i][j];
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = mat[i][j] + min({solve(n , i + 1 , j, mat , dp) , solve(n , i + 1 , j - 1, mat , dp) , solve(n , i + 1 , j + 1, mat , dp)});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n + 1 , vector<int>(n + 1 , -1));
        if(n == 1)
            return matrix[0][0];
        int ans = 10000;
        for(int i = 0 ;i < n;i++){
            ans = min(ans , solve(n , 0 , i , matrix , dp));
        }
        return ans;
    }
};