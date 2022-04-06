// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	long long multiply(int a,int b,int m)
	{
	    long long ans = 1;
	    for(int i = 0 ; i < b ; i++)
	    {
	        ans *= a;
	        if(ans > m)
	            return -1;
	    }
	    if(ans == m)
	        return -2;
	    return ans;
	}
	//2,4,8,16...
	//3,9,27,81...
	//As it is monotnoically increasing, so we can apply binary search
	//The naswe will always lie between 1 and m
	//shrink the array till the diffrence between high and low is<1e-6 or 5 decimal spaces error
	int NthRoot(int n, int m)
	{
	    int low = 1 , high = m;
	    if(m == 1)
	        return 1;
	   int ans;
	    while(low <= high)
	    {
	        int mid = low + (high - low)/2;
	        int temp = multiply(mid , n , m);
	        if(temp == -2)
	            return mid;
	        else if(temp == -1)
	        {
	            high = mid - 1;
	        }
	        else
	           ans = low ,  low = mid + 1;
	    }
	    return -1;
	    // Code here.
	}  
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends