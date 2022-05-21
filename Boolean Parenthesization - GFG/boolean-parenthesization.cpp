// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
#define mod 1003;
class Solution{
public:
    int solve(string& s , int i , int j , bool isTrue , vector<vector<vector<int>>>& dp)
    {
        if(i > j)
        {
            return 0;
        }
        if(i == j)
        {
            if(isTrue)
            {
                return s[i] == 'T';
            }
            else
            {
                return s[i] == 'F';
            }
        }
        if(dp[i][j][isTrue] != -1)
            return  dp[i][j][isTrue];
        int ways = 0;
        for(int ind = i + 1 ; ind < j ; ind += 2)
        {
            int lT = solve( s , i , ind - 1 , 1 , dp) % mod;
            int lF = solve( s , i , ind - 1 , 0 , dp) % mod;
            int rT = solve( s , ind + 1 , j , 1 , dp) % mod;
            int rF = solve( s , ind + 1 , j , 0 , dp) % mod;
            
            int a = (lT * rT) % mod;
            int b = (lT * rF) % mod;
            int c = (rT * lF) % mod;
            int d = (rF * lF) % mod;
            if(s[ind] == '&')
            {
                if(isTrue)
                {
                    ways += a;
                }
                else
                {
                    ways +=  b + c + d;
                }
            }
            else if(s[ind] == '|')
            {
                if(isTrue)
                {
                    ways += a + b + c;
                }
                else
                {
                    ways += d;
                }
            }
            else
            {
                if(isTrue)
                    {
                        ways += b + c;
                    }
                    else
                    {
                        ways += a + d;
                    }
            }
        }
        return  dp[i][j][isTrue] = ways % mod;
    }
    int countWays(int n, string s){
        vector<vector<vector<int>>> dp(n , vector<vector<int>>(n , vector<int>(2 , -1)));
        return solve(s , 0 , n - 1 , 1 , dp);
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends