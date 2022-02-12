// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int solve(int arr[] , int index , int sum , vector<vector<int>>& dp)
    {
        if(sum < 0)
        {
            return 0;
        }
        if(sum == 0)
            return 1;
        if(index == 0)
        {
            if(arr[0] == sum)
                return 1;
            else
                return 0;
        }
        if(dp[index][sum] != -1)
            return dp[index][sum];
        int l = solve(arr , index - 1 , sum , dp);
        int r = solve(arr ,index - 1 , sum - arr[index] , dp);
        
        return dp[index][sum] = (l==1 or r==1)?1 : 0;
        
        
    }
    bool isSubsetSum(int n, int arr[], int sum){
        vector<vector<int>> dp(n + 1 , vector<int>(sum + 1 , -1));
        return solve(arr , n - 1, sum , dp);
        // code here 
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends