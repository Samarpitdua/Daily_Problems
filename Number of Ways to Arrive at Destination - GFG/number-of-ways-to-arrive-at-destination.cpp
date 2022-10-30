//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define mod 1000000007
class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
         vector<pair<long long int , long long int>> adj[n];
        for(auto x : roads)
        {
            adj[x[0]].push_back({x[1] , x[2]});
            adj[x[1]].push_back({x[0] , x[2]});
        }
        priority_queue<pair<long long int ,long long  int> , vector<pair<long long int , long long int>> , greater<pair<long long int , long long int>> > pq;
        pq.push({0 , 0});
        vector<long long int> ways(n , 0) , dist(n , 1e9);
        ways[0] = 1 , dist[0] = 0;
        while(!pq.empty())
        {
            long long int distance = pq.top().first;
            long long int node = pq.top().second;
            pq.pop();
            for(auto x : adj[node])
            {
                int adjnode = x.first;
                long long edw = (distance + x.second)%mod;
                if(dist[adjnode] > edw)
                {
                    dist[adjnode] = edw;
                    pq.push({edw , adjnode});
                    ways[adjnode] = ways[node];
                    
                }
                else if(dist[adjnode] == edw)
                    ways[adjnode] = (ways[adjnode] + ways[node]) % mod;
            }
        }
        return ways[n - 1] % mod;
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends