//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        int ans = 0 , sum = 0;
        map<int , int> mp;
        mp[0] = 0;
        for(int i = 0; i < n ; i++){
            sum += a[i];
            // if(sum == k){
            //     ans = i + 1;
            // }
            if(mp.count(sum - k)){
                ans = max(ans , i - mp[sum - k] + 1);
            }
            if(!mp.count(sum)){
                mp[sum] = i + 1;
            }
        }
        return ans;
        // int ans = 0;
        // int sum = 0;
        
        // unordered_map<int,int> Map;
        // Map[0] = 0;
        
        // for(int i=0; i<N; i++)
        // {
        //     sum += arr[i];
        //     if(Map.count(sum - K))
        //         ans = max(ans, i - Map[sum - K] + 1);
            
        //     if(!Map.count(sum))
        //     Map[sum] = i+1;
        // }
        
        // return ans;
        // Complete the function
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends