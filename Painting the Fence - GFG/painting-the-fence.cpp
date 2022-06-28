// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long solve(int n , int k , vector<long long int>& dp){
        if(n == 1)
            return k;
            if(n == 2)
            return (k + (k - 1) * k) % 1000000007;
        if(dp[n] != -1)
            return dp[n];
        else
        return dp[n] = (((k - 1) *solve(n - 2 ,k  , dp)) % 1000000007 + ((k - 1)*solve(n - 1 , k , dp)) % 1000000007) % 1000000007;
    }
    
    long long countWays(int n, int k){
        vector<long long int> dp(n + 1 , -1);
        return solve(n , k , dp);
        // code here
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends