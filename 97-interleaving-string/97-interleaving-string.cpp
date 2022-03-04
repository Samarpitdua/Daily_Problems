class Solution {
public:
int solve(string& s1, string& s2, string& s3 , int i , int j , int k , vector<vector<int>>& dp)
    {
        if(k < 0)
            return true;
        
        if(i < 0 and j < 0)
            return k < 0;
        if(i < 0)
        {
            while(j >= 0)
            {
                if(s3[k] == s2[j])
                    k--;
                else
                    return 0;
                j--;
            }
            if(k < 0)
                return 1;
            return 0;
        }
        if(j < 0)
        {
            while(i >= 0)
            {
                if(s3[k] == s1[i])
                    k--;
                else
                    return 0;
                i--;
            }
            if(k < 0)
                return 1;
            return 0;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int a = 0 , b = 0 , c = 0;
        if(s3[k] != s2[j] and s3[k] != s1[i])
            return dp[i][j] = 0;
        
        if( s3[k] == s1[i])
            a = solve(s1 , s2 , s3 , i - 1, j , k - 1 , dp);
        
        if(s3[k] == s2[j])
        {
            b = solve(s1 , s2 , s3 , i , j - 1 , k - 1 , dp);
        }
        // return a or b;
        return dp[i][j] = a or b;
    }
    bool isInterleave(string s1, string s2, string s3) {
        
        int n1 = s1.size() , n2 = s2.size() , n3 = s3.size();
        
        vector<vector<int>> dp(n1 + 1 , vector<int>(n2 + 1 , -1));
        
        if((n1 + n2) != n3)
            return false;
        
        return solve(s1 , s2 , s3 , n1 - 1, n2 - 1, n3 - 1 , dp);
    }
};