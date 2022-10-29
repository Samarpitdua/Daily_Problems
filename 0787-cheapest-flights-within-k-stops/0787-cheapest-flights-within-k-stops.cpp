class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<pair<int , int>> adj[n + 1];
        for( auto f : flights )
            adj[f[0]].push_back( { f[1], f[2] } );
        
        queue<pair<int , pair<int , int>>> q;
        q.push( { 0, {src, 0} } ); // cost, vertex, hops
        vector<int> dist(n , 1e9);
        dist[src] = 0;
        while( !q.empty() ) {
            auto t = q.front(); 
            q.pop();
            int stop = t.first;
            int node = t.second.first;
            int cost = t.second.second;
            if(stop > K)
                continue;
            for(auto x : adj[node])
            {
                int adjNode = x.first;
                int edW = x.second;
                if((cost + edW) < dist[adjNode])
                {
                    dist[adjNode] = cost + edW;
                    q.push({stop + 1 , {adjNode , cost + edW}});
                }
            }
        }
        if(dist[dst] == 1e9)
        return -1;
        return dist[dst];
    }
};
