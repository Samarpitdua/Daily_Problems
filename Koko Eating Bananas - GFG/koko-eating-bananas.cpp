//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(vector<int> piles , int n , int mid , int h)
    {
        int ct = 0;
        for(int i = 0 ; i < n ; i++)
        {
                ct += (piles[i] / mid);
                if(piles[i] % mid > 0)
                ct++;
                if(ct > h)
                    return false;
        }
        return (ct <= h);
    }
    int Solve(int n, vector<int>& piles, int h) {
        int low = 1 , high = 1e9;
        sort(piles.begin() , piles.end()  ,greater<int>());
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(solve(piles , n , mid , h))
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
        // Code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends