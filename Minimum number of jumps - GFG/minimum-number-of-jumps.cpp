// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        int ct = 0 , i = 0;
        if(n == 1)
        return 0;
        for( i = 0 ; i < n ;)
        {
            int maxInd = -1 , ind = -1;
            ct++;
            if(i + arr[i] >= (n-1))
            return ct;
            for(int j = i + 1 ; j < n and j <= i + arr[i] ;j++)
            {
                if(maxInd < arr[j] + j)
                {
                    maxInd = j + arr[j];
                    ind = j;
                }
            }
            if(maxInd >= (n - 1))
            {
                return (1 + ct);
            }
            if(ind == -1)
                return -1;
            if(i == ind)
            return -1;
            i = ind;
        }
        return ct;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends