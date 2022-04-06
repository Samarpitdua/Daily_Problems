// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    void solve(vector<vector<int>>& ans , vector<int> arr , int n , int ind,vector<int>& temp)
{
            ans.push_back(temp);
        while(ind < n)
        {
            temp.push_back(arr[ind]);
            solve(ans , arr , n , ind + 1 , temp);
            temp.pop_back();
            while(ind < n and arr[ind] == arr[ind + 1])
                ind++;
            ind++;
        }
    }
    vector<vector<int>> AllSubsets(vector<int> arr, int n)
    {
        vector<vector<int>> ans;
        sort(arr.begin() , arr.end());
        vector<int>  temp;
        solve(ans , arr , n ,0 , temp);
        return ans;
        // code here 
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends