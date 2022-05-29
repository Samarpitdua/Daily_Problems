// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    string canJump(long long N) {
        int temp = __builtin_popcount(N);
        if(temp == 1)
            return "True";
        else
            return "False";
        // code here
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.canJump(N) << endl;
    }
    return 0;
}  // } Driver Code Ends