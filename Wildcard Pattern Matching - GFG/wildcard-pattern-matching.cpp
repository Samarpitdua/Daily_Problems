// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    bool solve(string& s , string& t , int i , int j , vector<vector<int>> &dp){
    if(i < 0 and j < 0){
        return true;
    }
    if(i < 0){
        while(j >= 0)
        {
            if(t[j] != '*')
                return false;
           j--;
        }
        return true;
    }
    if(j < 0)
    {
        return false;
    }
    if(dp[i][j] != -1)
        return dp[i][j];
    if(s[i] == t[j] or t[j] =='?'){
        return dp[i][j] = solve(s , t ,i - 1 , j - 1 , dp);
    }
    else if(t[j] == '*'){
        return dp[i][j] = solve(s , t ,i - 1 , j - 1 , dp) or solve(s , t ,i , j - 1 , dp) or solve(s , t ,i - 1 , j , dp);
    }
    return dp[i][j] = false;
        
}
int wildCard(string pattern, string text)
{
    int n = text.size() , m = pattern.size();
    vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , -1));
    return solve(text , pattern , n - 1 ,m - 1 , dp);
   // Write your code here.
}


};

// { Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}
  // } Driver Code Ends