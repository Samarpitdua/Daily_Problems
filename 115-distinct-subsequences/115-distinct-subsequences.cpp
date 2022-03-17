class Solution {
public:
    //given a string babgbag
    //how many times another string "bag" appears in that string
    //ans = 5
    //trying all ways : recursion
    //count all ways
    //write recursion
    //express everything in term  of recursion f(i,j)
    //explore all possiblity
    //return sum of all possibilities
    //base case -> ask yourself
    //memoization is giving tle
    //so apply tabulation(convert to 1 based index)
    int solve(string s , string t , int i , int j , vector<vector<int>>& dp)
    {
        if(i < 0)
        {
            return (j < 0);
        }
        if(j < 0)
        {
            return 1;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int a = 0 , b = 0;
        if(s[i] == t[j])
            a = solve(s , t ,i - 1 , j - 1 , dp);
        b = solve(s , t , i - 1 , j , dp);
        return dp[i][j] = a + b;
    }
    int numDistinct(string s, string t) {
        
       int n = s.size() , m = t.size();
       vector<vector<long double>> dp(n + 1 , vector<long double>(m + 1 , 0));
        for(int i = 0 ; i <= n ; i++)
        {
            for(int j = 0 ; j <= m ; j++)
            {
                if(j == 0)
                    dp[i][j] = 1;
                else if(i == 0)
                    dp[i][j] = 0;
                else
                {
                    if(s[i - 1] == t[j - 1])
                        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                    else
                        dp[i][j] = dp[i - 1][j];
                }
                    
            }
        }
       return int(dp[n][m]);
    }
};