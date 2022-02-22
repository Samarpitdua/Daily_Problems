// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    int countKdivPairs(int a[], int n, int k)
    {
        int ans = 0;
        int ct = 0;
        map<int , int> mp;
        for(int i = 0 ; i < n ;i++)
        {
            if(a[i] % k == 0)
                ct++;
            mp[a[i] % k]++;
        }
        ans += (ct * (ct - 1)) / 2;
        
        for(int i = 1 ; i <= k / 2 ;i++)
        {
            if(i == (k - i))
                continue;
            int temp = k - i;
            ans += mp[temp] * mp[i];
        }
        if(k % 2 == 0)
        {
            int u = mp[k / 2];
            ans += (u * (u - 1) / 2);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}
  // } Driver Code Ends