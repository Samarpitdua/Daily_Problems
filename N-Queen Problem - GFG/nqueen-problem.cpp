// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isValid(int row ,int col ,vector<string>& temp , int n)
    {
        for(int i = 0 ; i < col ; i++)
        {
            if(temp[row][i] == 'Q')
            return false;
        }
        int i = row , j = col;
        while(i >= 0 and j >= 0)
        {
            if(temp[i][j] == 'Q')
            return false;
            i-- , j--;
        }
        i = row , j = col;
        while(i < n and j >= 0)
        {
            if(temp[i][j] == 'Q')
            return false;
            i++ , j--;
        }
        return true;
    }
    void solve(vector<vector<string>>& ans , int n , int row , int col , vector<string>& temp)
    {
        if(col == n)
        {
            ans.push_back(temp);
            return;
        }
        for(int i = row ; i < n ;i++)
        {
            if(isValid(i , col , temp , n))
            {
                temp[i][col] = 'Q';
                solve(ans , n , row , col + 1, temp);
                temp[i][col] = '.';
            }
        }
        
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<string>> ans;
        vector<vector<int>> ans2;
        vector<string> temp(n);
        string s(n , '.');
        for(int i = 0 ; i < n ;i++)
        {
            temp[i] = s;
        }
        solve(ans , n , 0 , 0 ,temp);
        
        for(int i = 0 ; i < ans.size() ;i++)
        {
            vector<int> temp2;
            for(int j = 0 ; j < n ; j++)
            {
                for(int k = 0 ; k < n; k++)
                {
                    if(ans[i][j][k] == 'Q')
                    {
                        temp2.push_back(k + 1);
                    }
                }
            }
            ans2.push_back(temp2);
        }
        sort(ans2.begin() , ans2.end());
        return ans2;
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
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends