//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int gcd(int a , int b)
  {
      if(b < a)
      swap(a , b);
      if(a == 0)
      return b;
      return gcd(a , b % a);
  }
    vector<long long> lcmAndGcd(long long A , long long B) {
        vector<long long>ans;
        ans.push_back((A*B)/gcd(A,B));
        ans.push_back(gcd(A,B));
        
        return ans;
        
        // code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends