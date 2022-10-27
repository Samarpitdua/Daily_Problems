//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
#define m 1000000007
class Solution {
	public:
		int NthTerm(int n){
		    if(n == 1)
		    {
		        return 2;
		    }
		   long long int temp = 2;
		    long long int ct = 2;
		    for(int i = 2 ; i <= n ;i++)
		    {
		        temp = (((temp%m) * (ct%m))%m + 1)%m;
		      //  temp %= ;
		        ct++;
		    }
		    return temp;
		    // Code  here
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.NthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends