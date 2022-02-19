// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

















int solve(int cuts[] , int index , vector<vector<int>>& dp ,int length)
{
    if(index == 0)
    {
        return cuts[0] * length;
    }
    if(dp[index][length] != -1)
        return dp[index][length];
    int take = INT_MIN;
    int notTake = solve(cuts , index - 1 , dp , length);
    if(index < length)
        take = cuts[index] + solve(cuts , index , dp , length - index - 1);
    return dp[index][length] = max(take , notTake);
}
class Solution{
  public:
    int cutRod(int cuts[], int n) {
         vector<vector<int>> dp(n , vector<int>(n + 1 , -1));
        return solve(cuts , n - 1 , dp , n);
        //code here
    }
};















// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends