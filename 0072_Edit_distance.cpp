//Approach 1: Memoization
class Solution {
public:
    int solve(string s,string t,int m,int n,vector<vector<int>>& dp)
    {
        if(m<0)
            return n+1; 
        if(n<0)
            return m+1;
        if(dp[m][n]!=-1)
            return dp[m][n];
        if(s[m]==t[n])
            return dp[m][n]=solve(s,t,m-1,n-1,dp);
        else
        {
            int a=1+solve(s,t,m,n-1,dp);
            int b=1+solve(s,t,m-1,n-1,dp);
            int c=1+solve(s,t,m-1,n,dp);
            return dp[m][n]=min({a,b,c});
        }
            
    }
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(word1,word2,m-1,n-1,dp);
    }
};
class Solution {
public:
    //Approach : 2 -> Tabulation
    //Ques bahut hee asaan h. 3 options h hmare paas :
    //Base case agr equal h toh 0 add kro aur i and j ko ek ek aage badhao
    //a) ya toh replace krdo, is case me hum 1 add krenge operations me and i aur j ko 
    //ek step aage badha denge
    int solve(string word1, string word2, int m ,int n ,vector<vector<int>>dp)
    {
        for(int i = 0;i <= m;i++)
        {
            for(int j = 0;j <= n;j++)
            {
                if(i == 0)
                {
                    dp[i][j] = j;
                }
                else if(j == 0)
                    dp[i][j] = i;
                else
                {
                    if(word1[i-1] == word2[j-1])
                    {
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else
                    {
                        dp[i][j] = 1+min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});
                    }
                }
            }
        }
        return dp[m][n];
    }
    int minDistance(string word1, string word2) {
        int m = word1.size(),n = word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(word1,word2,m,n,dp);
    }
};
