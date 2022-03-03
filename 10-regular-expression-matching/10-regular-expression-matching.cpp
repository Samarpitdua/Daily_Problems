class Solution {
public:
    int solve(string& s , string& p , int i , int j , vector<vector<int>>& dp)
    {
        if(j == p.size())
        {
             // cout<<i<<" "<<j<<endl;
            return i == s.size() ; 
        }
        
        if(i == s.size())
        {
            if((j+1)<p.size() and p[j+1]=='*')
                return solve(s , p , i , j + 1 , dp);
            if(p[j] != '*')
                return 0;
            return solve(s , p , i , j + 1 , dp);
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(p[j] == '*')
        {
            int a = solve(s , p , i , j + 1 , dp);
            int b = 0;
            if(j > 0)
            {
                if(p[j - 1] == s[i] || p[j - 1] =='.')
                {
                    b = solve(s , p , i + 1 , j , dp);
                }
            }
            // cout<<"yy"<<a<<" "<<b<<endl;
            return dp[i][j] = a || b;
        }
        else if(p[j+1]=='*')
        {
            int a=0,b=0;
                if(s[i] == p[j])
                    a = solve(s , p , i + 1 , j + 1 , dp);
            b = solve(s , p , i , j + 1 , dp);
            return a or b;
        }
        else
        {
            int a = 0 , b = 0;
            if(i < s.size() and ( (s[i] == p[j]) or p[j] == '.' ))
            {
                 
                a = solve(s , p , i + 1 , j + 1 , dp);
            }
            
            else if((j+1)<p.size() and p[j+1]=='*')
                b = solve(s , p , i , j + 1 , dp);
            
            return dp[i][j] = a or b;
        }
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , -1));
        return solve(s , p , 0 , 0 , dp);
    }
};