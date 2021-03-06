// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
// #define ll long long
class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
    vector<vector<long long int>> ans(n);
	vector<long long int> temp;
	for(int i = 0 ; i < n ; i++)
	{
		temp.resize(i + 1);
		temp[0] = 1;
		temp[i] = 1;
		for(int j = 1 ; j < i ; j++)
		{
			temp[j] = (ans[i - 1][j - 1] + ans[i - 1][j]) % 1000000007;
		}
		ans[i] = temp;
	}
	return temp;
        // code here
    }
};


// { Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}
  // } Driver Code Ends