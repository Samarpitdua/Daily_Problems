class Solution {
public:
    //Gap method
    string longestPalindrome(string s) {
        int n=s.size();
        vector< vector< bool > >dp(n , vector<bool>(n,false) );
        int ans1=-1,ans2=-1;
        for(int gap = 0;gap < n; gap++)
        {
            for(int i = 0,j = gap;j < n;i++,j++)
            {
                if(gap == 0)
                    dp[i][j] = true;
                else if(gap == 1)
                {
                    if(s[i] == s[j])
                        dp[i][j] = true;
                }
                else
                {
                    if(s[i] == s[j] and dp[i+1][j-1])
                        dp[i][j]=true;
                }
                if(dp[i][j])
                {
                        ans1 = i;
                        ans2 = j;
                }
            }
        }
        string ans="";
        for(int i=ans1;i<=ans2;i++)
            ans += s[i];
        return ans;
        
    }
};