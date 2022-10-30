
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod  = 1e9 + 7;
        vector<vector<pair<int , int>>> adj(n);
        for(auto x : roads)
        {
            adj[x[0]].push_back({x[1] , x[2]});
            adj[x[1]].push_back({x[0] , x[2]});
        }
        priority_queue<pair<long long int ,int> , vector<pair<long long int , int>> , greater<pair<long long int , int>> > pq;
        pq.push({0 , 0});
        vector<long long int> ways(n , 0) , dist(n , LONG_MAX);
        ways[0] = 1 , dist[0] = 0;
        while(!pq.empty())
        {
            long long int distance = pq.top().first;
            long long int node = pq.top().second;
            pq.pop();
            for(auto& x : adj[node])
            {
                int adjnode = x.first;
                long long edw = (distance + x.second);
                if(dist[adjnode] > edw)
                {
                    dist[adjnode] = edw;
                    pq.push({edw , adjnode});
                    ways[adjnode] = ways[node]%mod;
                    
                }
                else if(dist[adjnode] == edw)
                {
                    ways[adjnode] += ways[node] ;
                    ways[adjnode] %= mod;
                }
                
            }
        }
        return ways[n - 1] % mod;
    }
};