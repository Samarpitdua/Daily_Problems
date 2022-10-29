//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        unordered_map<string,set<string>> mp;
        for(int i=0;i<n;i++){
            string str="";
            for(int j=0;j<contact[i].size();j++){
                str=str+contact[i][j];
                mp[str].insert(contact[i]);
            }
        }
        vector<vector<string>> vec;
        string q="";
        for(auto x : s){
            q = q + x;
            if(mp.find(q)!=mp.end())
            {
                vector<string> v(mp[q].begin(),mp[q].end());
                vec.push_back(v);
            }
            else{
                vector<string> v(1,"0");
                vec.push_back(v);
            }
        }
        return vec;
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends