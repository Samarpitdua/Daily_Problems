// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
 
    int solve(vector<vector<int>>& dp , vector<int>& arr , int i , int j)
    {
        if(i >= j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int mini = 1e9;
        for(int k = i ; k < j ;k++)
        {
            int steps = (arr[i - 1] * arr[k] * arr[j]) + solve(dp , arr , i , k)
            + solve(dp , arr , k + 1 , j);
            mini = min(mini , steps);
        }
        return dp[i][j] = mini;
    }
    int matrixMultiplication(int n, int arr[])
    {
        vector<int> v(n);
        for(int i=0;i<n;i++)
        v[i]=arr[i];
         vector<vector<int>> dp(n , vector<int>(n , -1));
        return solve(dp , v , 1 , n - 1);
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
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends