//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int dfs(vector<int> graph[] , int node , vector<int>& vis)
  {
      vis[node] = 1;
      for(auto child : graph[node])
      {
          if(!vis[child])
            dfs(graph , child, vis);
      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        int ans = 0;
        vector<int> graph[V];
        vector<int> vis(V , 0);
        for(int i = 0 ; i  < adj.size() ;i++)
        {
            for(int j = 0 ; j  < adj[0].size() ;j++)
            {
                if(adj[i][j] == 1)
                    graph[i].push_back(j);
            }
        }
        for(int x = 0 ; x < V ;x++)
        {
            if(vis[x] == 0)
            {
                ans++;
                dfs(graph , x , vis);
            }
        }
        return ans;
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends