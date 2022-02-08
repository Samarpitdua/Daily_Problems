// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int temp = -1;
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int ct = 0;
        int i = 0 , j = 0;
        for( ; i < n and j < m ;)
        {
            ct++;
            if(arr1[i] > arr2[j])
            {
                temp = arr2[j];
                j++;
            }
            else
            {
                temp = arr1[i];
                i++;
            }
            if(ct == k)
                return temp;
        }
        while(i < n)
        {
            ct++;
            if(ct == k)
                return arr1[i];
            i++;
        }
        while(j < m)
        {
            ct++;
            if(ct == k)
                return arr2[j];
            j++;
        }
        return -1;
        
        
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends