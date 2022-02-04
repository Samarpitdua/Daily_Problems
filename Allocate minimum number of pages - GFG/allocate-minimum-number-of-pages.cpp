// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int a[], int n, int m) 
    {
        if(n < m)
            return -1;
        if(n == 1)
            return a[0];
        int sum = 0 , ans = -1;
        for(int i = 0 ; i < n ;i++)
        {
            sum += a[i];
        }
        int l = *min_element(a , a + n);
        int r = sum;
        
        while(l <= r)
        {
            if(l == r)
                return l;
       //     cout<<l<<" "<<r<<"\n";
            // cout<<"hi ";
            int mid = l + (r - l) / 2;
            int ct = 1 , temp = 0 , p = 0 ;
            for(int i = 0 ; i < n ;)
            {
                if(a[i] > mid)
                {
                    p = 1;
                    break;
                }
                
                temp += a[i];
                if(temp > mid)
                {
                    temp -= a[i];
                    temp = 0;
                    ct++;
                    continue;
                }
                else
                {
                    i++;
                    continue;
                }
            }
            
            if(p==1)
            {
                l = mid + 1;
                continue;
            }
            if(ct == m)
            {
                ans = mid;
                r = mid ;
            }
            else if(ct > m)
            {
                l = mid + 1 ;
            }
            else
            {
                r = mid  ;
            }
        }
        return ans;
        //code here
    }
};
//19
// 2 9 12 18 22 39 42 47 56 59 66 73 80 80 82 86 88 91 99
// 3

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends