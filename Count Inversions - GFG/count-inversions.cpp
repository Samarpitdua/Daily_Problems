// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(vector<long long int>& v , long long int left , long long int right , long long int mid)
{
    long long int n1 = mid - left + 1;
    long long int n2 = right - mid;
    long long int arr1[n1] , arr2[n2];
    for(long long int i = 0 ; i < n1 ;i++)
    {
        arr1[i] = v[left + i];
    }
    for(long long int i = 0 ; i < n2 ;i++)
    {
        arr2[i] = v[mid + 1 + i];
    }
    long long int i = 0 , j = 0;
    long long int k = left , ct = 0;
    for( ; i < n1 and j < n2 ;)
    {
        if(arr1[i] <= arr2[j])
        {
            v[k++] = arr1[i++];
        }
        else
        {
            v[k++] = arr2[j++];
            ct += (mid -( i + left) + 1);
        }
    }
    while(i < n1)
        v[k++] = arr1[i++];
    while(j < n2)
        v[k++] = arr2[j++];
    //cout<<ct<<" ";
    return ct;
}
long long int mergeSort(vector<long long int>& v , long long int left , long long int right)
{
    long long int ct = 0 , mid;
    if(left < right)
    {
         mid = (left + right) / 2;
         ct += mergeSort(v , left , mid);
         ct += mergeSort(v , mid + 1 , right);
        ct += merge(v , left ,  right , mid);
    }
    return ct;
}
long long int inversionCount(long long arr[], long long n)
{
    vector<long long int> v(n);
    for(long long int i = 0 ; i < n ;i++)
    {
        v[i] = arr[i];
    }
    return mergeSort(v , 0 , n - 1);
    // Your Code Here
}


};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends