//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        vector<int> ans;
        while(N)
        {
            int diff;
            if(N >= 2000)
            diff = 2000;
            else if(N >= 500)
            diff = 500;
            else if(N >= 200)
            diff = 200;
            else if(N >= 100)
            diff = 100;
            else if(N >= 50)
            diff = 50;
            else if(N >= 20)
            diff = 20;
            else if(N >= 10)
            diff = 10;
            else if(N >= 5)
            diff = 5;
            else if(N >= 2)
            diff = 2;
            else
            diff = 1;
            
            ans.push_back(diff);
            N -= diff;
        }
        return ans;
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends