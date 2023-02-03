//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int solve(int ind, vector<int> &dp, int *arr) {
	    if(ind == 0) return arr[0];
	    
	    if(ind < 0) return 0;
	    
	    if(dp[ind] != -1) return dp[ind];
	    
	    int nottake = solve(ind - 1, dp, arr); // no adjacent;
	    int take = arr[ind] + solve(ind - 2, dp, arr);
	    
	    return dp[ind] = max(take, nottake);
	    
	}
	int findMaxSum(int *arr, int n) {
	    vector<int> dp(n + 1, -1);
	    return solve(n - 1, dp, arr);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends