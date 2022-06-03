// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int n , int val[] , int wt[] , int W , int ind , vector<vector<int>>& dp)
    {
        if(ind == n)
            return 0;
        if(W < 0)
            return 0;
        if(dp[ind][W] != -1)
            return dp[ind][W];
        if(wt[ind] > W)
        {
            return dp[ind][W] = solve(n , val , wt, W , ind + 1 , dp);
        }
        else
        {
            return dp[ind][W] = max(solve(n , val , wt, W , ind + 1 , dp) , val[ind] + solve(n , val , wt, W - wt[ind], ind , dp));
        }
    }
    int knapSack(int n, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(n , vector<int>(W + 1 , -1));
        return solve(n , val , wt , W, 0 , dp);
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends