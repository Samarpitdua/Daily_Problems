// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int solve(vector<vector<int>>& dp , int coins[] , int m , int value , int index)
	{
	    if(index == m)
	    {
	        if(value == 0)
	            return 0;
	        else
	            return 10000000;
	    }
	    if(dp[index][value] != -1)
	        return dp[index][value];
	    if(coins[index] <= value)
	    {
	        return dp[index][value] = min(1 + solve(dp , coins , m , value - coins[index] , index) , solve(dp , coins , m , value , index + 1));
	    }
	    else
	        return dp[index][value] = solve(dp , coins , m , value , index + 1);
	}
	int minCoins(int coins[], int m, int v) 
	{ 
	    vector<vector<int>> dp(m + 1 , vector<int>(v + 1 , -1));
	    long long ans = solve(dp , coins , m , v , 0);
	    if(ans >= 10000000)
	        return -1;
	   return ans;
	    // Your code goes here
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends