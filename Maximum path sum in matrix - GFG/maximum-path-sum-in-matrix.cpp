// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(vector<vector<int>>& mat , int i ,int j , vector<vector<int>>& dp , int n){
        // if(i == n - 1 && j == n - 1)
        //     return mat[i][j];
        if(i >= n or j >= n or j < 0 or i < 0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = mat[i][j] + max({solve(mat , i + 1 , j , dp , n) , solve(mat , i + 1 , j - 1, dp , n) , solve(mat , i  + 1, j + 1, dp , n)});
        
    }
    int maximumPath(int n, vector<vector<int>> mat)
    {
        vector<vector<int>> dp(n, vector<int>(n ,-1));
        int ans = INT_MIN;
        for(int i =0 ; i < n ;i++){
            ans = max(ans , solve(mat , 0 , i , dp , n));
        }
        return ans;
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
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends