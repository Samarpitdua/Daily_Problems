class Solution {
public:
    bool pallu(string& s , int i , int j){
        while(i < j){
            if(s[i] != s[j])
                return false;
            i++ , j--;
        } 
        return true;
        
    }
    int solve(int i , int j , string& s , vector<int>& dp){
        if(i >= j)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int ans = INT_MAX;
        for(int k = i ; k < j ;k++){
            if(pallu(s , i , k))
            {
                ans = min(ans , 1 + solve(k + 1 , j , s , dp));
            }
        }
        return dp[i] = ans;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1 , -1);
        return solve(0 , n, s , dp) - 1;
        
    }
};