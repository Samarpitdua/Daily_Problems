//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 



// } Driver Code Ends
class Solution{
  public:
    int maxDistance(int arr[], int n) 
    { 
        int maxi = INT_MIN, mini = INT_MAX;
        int maxi2 = INT_MIN, mini2 = INT_MAX;
        if(n == 1)
        return 0;
        for(int i = 0 ; i < n ;i++)
        {
            maxi2 = max(maxi2 , arr[i] - i);
            maxi = max(maxi , arr[i] + i);
            mini2 = min(mini2 , arr[i] - i);
            mini = min(mini , arr[i] + i);
        }
        return max(maxi - mini , maxi2 - mini2);
        // Complete the function
    } 
};

//{ Driver Code Starts.
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i = 0; i<n; i++)
	        cin>>arr[i];
	    Solution obj;
	    cout<<obj.maxDistance(arr, n)<<endl;
	}
} 

// } Driver Code Ends