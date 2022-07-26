class Solution {
public:
int numBusesToDestination(vector<vector<int>>& routes, int src, int target) {
if(src == target) return 0;

    int N = 1e6 + 10;
    vector<int>adj[N];
    
    for(int i=0; i<routes.size(); i++){
        int busNo = i;
        
        for(int j=0; j<routes[i].size(); j++){
            int route = routes[i][j];
            adj[route].push_back(busNo);
        }
    }
    
    queue<pair<int,int>>q;
    q.push({src, 0});
    
    vector<int>visitedBus(501, 0), visitedRoute(N, 0);
    visitedRoute[src] = 1;
    
    while(!q.empty()){
        int curRoute = q.front().first;
        int count = q.front().second;
        q.pop();
        
        if(curRoute == target) return count;
        
        vector<int>busNumbers = adj[curRoute];
        
        for(int i=0; i<busNumbers.size(); i++){
            int busNo = busNumbers[i];
            
            if(visitedBus[busNo]) continue;
            
            for(int j=0; j<routes[busNo].size(); j++){
                if(visitedRoute[routes[busNo][j]]) continue;
                
                visitedRoute[routes[busNo][j]] = 1;
                q.push({routes[busNo][j], count+1});
            }
            visitedBus[busNo] = 1;
        }
    }
    
    return -1;
}};