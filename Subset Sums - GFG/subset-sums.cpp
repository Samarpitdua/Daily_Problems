//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
void solve(vector<int>& arr , int sum , int ind , vector<int>& ans)
{
    if(ind < 0)
    {
        ans.push_back(sum);
        return;
    }
    solve(arr , sum + arr[ind] , ind - 1 , ans);
    solve(arr , sum , ind - 1 , ans);
}
    vector<int> subsetSums(vector<int> arr, int n)
    {
        vector<int> ans;
        int sum = 0;
        solve(arr , sum , n - 1, ans);
        return ans;
        // Write Your Code here
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends