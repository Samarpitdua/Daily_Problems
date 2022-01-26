// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int *constructST(int arr[],int n);


int RMQ(int st[] , int n, int a, int b);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        int Q;
        cin>>Q;



        int *segTree = constructST(A,N);

        for(int i=0;i<Q;i++)
        {
            int start,e;
            
            cin>>start>>e;
            if(start>e)
            {
                swap(start,e);
            }
            cout<<RMQ(segTree,N,start,e)<<" ";
        }
        cout<<endl;
    }
}
// } Driver Code Ends

vector<int>seg(10000);
/* The functions which 
builds the segment tree */
void build(int low, int high, int arr[], int ind, vector<int>& seg)
{
    if(low == high)
    {
        seg[ind] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    build(low, mid, arr, 2 * ind + 1, seg);
    build(mid + 1, high, arr, 2 * ind + 2, seg);
    seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
}
int *constructST(int arr[],int n)
{
   // vector<int>seg(4 * n);
    build(0 , n - 1 , arr , 0 , seg);
  //Your code here
}


/* The functions returns the
 min element in the range
 from a and b */
 int query(int ind, int low,int high,int l,int r,vector<int>& seg)
{
    if(low >= l and high <= r)
        return seg[ind];
    if(low > r or high < l)
        return INT_MAX;
    int mid = (low + high) >> 1;
    int left = query(2 * ind + 1, low, mid, l, r, seg);
    int right = query(2 * ind + 2, mid + 1, high, l, r, seg);
    return min(left, right);
}
int RMQ(int st[] , int n, int a, int b)
{
    return query(0 , 0 , n - 1 , a , b , seg);
//Your code here
}