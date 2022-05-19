// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    int solve(int W , int wt[] , int val[] , int index , vector<vector<int>>& dp)
    {
        if(index == 0)
        {
            if(W >= wt[0])
                return val[0];
            else
                return 0;
        }
        if(dp[index][W] != -1)
            return dp[index][W];
        int right;
        if(wt[index] > W)
        {
            right = INT_MIN;
        }
        else
        {
            right = val[index] + solve(W-wt[index] , wt , val , index - 1  ,dp);
        }
        int left = solve(W , wt , val , index - 1  ,dp);
        return dp[index][W] = max(left , right);
        
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>>dp(n  , vector<int>(W + 1,0));
        for(int i = wt[0] ; i <= W ;i++)
        {
            dp[0][i] = val[0];
        }
        for(int i = 1 ; i < n ;i++)
        {
            for(int j = 0 ; j <= W ; j++)
            {
                 int right = INT_MIN;
                if(wt[i] <= j)
                {
                    right = val[i] + dp[i - 1][j-wt[i]];
                }
                int left = dp[i - 1][j];
                dp[i][j] = max(left , right);
            }
            
        }
       return dp[n - 1][W];
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends