// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        vector<int> parent(v) , key(v , INT_MAX);
        vector<bool> mstSet(v , false);
        key[0] = 0;
        parent[0] = -1;
        //priority queue will hold  distance and node
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
        // code here
        pq.push({key[0] , 0});
        
        while(!pq.empty())
        {
            int node = pq.top().second;
            pq.pop();
            mstSet[node] = true;
            for(auto x : adj[node])
            {
                int v = x[0];
                int dist = x[1];
                if(mstSet[v] == 0 and dist < key[v])
                {
                    parent[v] = node;
                    key[v] = dist;
                    pq.push({key[v] , v});
                }
            }
        }
        int sum = 0;
        for(auto x : key)
            sum += x;
        return sum;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends