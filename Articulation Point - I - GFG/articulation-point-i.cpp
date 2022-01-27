// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void dfs(int node , int parent , vector<int>& vis , vector<int>& tin , vector<int>& low , int& timer , vector<int> adj[] , vector<int>& art )
  {
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        timer++;
        int child = 0;
    //    cout<<"hi ";
        for(auto x : adj[node])
        {
            if(x == parent)
                continue;
            if(!vis[x])
            {
                dfs(x , node , vis , tin , low , timer , adj , art);
                low[node] = min(low[node] , low[x]);
                child++;
                if(low[x] >= tin[node] and parent != -1)
                {
                    //cout<<node<<" ";
                    art[node] = 1;
                }
            }
            else
                low[node] = min(low[node] , tin[x]);
        }
        if(parent == -1 and child > 1)
            art[node] = 1;
  }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int> low(V , -1) , tin(V , -1) , vis(V , 0) , art(V , 0);
        int timer = 0;
        for(int i = 0 ; i < V ;i++)
        {
            if(!vis[i])
                dfs(i , -1 , vis ,  tin , low , timer , adj , art);
        }
        vector<int> ans;
        for(int i = 0 ; i < V ; i++)
        {
            if(art[i])
                ans.push_back(i);
        }
        if(ans.size() == 0)
        {
            ans.push_back(-1);
            return ans;
        }
        return ans;
        
        // Code here
    }
};

// { Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends