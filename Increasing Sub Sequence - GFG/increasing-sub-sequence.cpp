// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int maxLength(string nums)
    {
        int ans = 0 , n = nums.size();
        vector<int> dp;
        for(int i = 0 ; i < n ;i++)
        {
            auto x = lower_bound(dp.begin() , dp.end() , nums[i]);
            if(x == dp.end())
                dp.push_back(nums[i]);
            else
            {
                *x = nums[i];
            }
        }
        return dp.size();
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
        string S;
        cin>>S;
        Solution ob;
        cout << ob.maxLength(S) << endl;
    }
    return 0; 
}  // } Driver Code Ends