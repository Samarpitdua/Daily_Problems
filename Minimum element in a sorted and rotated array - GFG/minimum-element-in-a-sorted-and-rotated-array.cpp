// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int findMin(int nums[], int n){
        int  l = 0 , r = n - 1;
        while(l < r)
        {
            int mid = l + (r - l) / 2;
            // if(mid == 0 and nums[mid] < nums[mid + 1] and nums[mid] < nums[n - 1])
            //     return nums[mid];
            // if(mid == n - 1 and nums[mid] < nums[mid - 1] and nums[mid - 1] < nums[0])
            //     return nums[mid];
            if(mid > 0 and nums[mid] < nums[mid - 1] )
            {
                return nums[mid];
            }
            else if(nums[mid] >= nums[l] and nums[mid] > nums[r])
                l = mid + 1;
            else
                r = mid - 1;
        }
        return nums[l];
        //complete the function here
    }
};

// { Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}  // } Driver Code Ends