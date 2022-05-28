class Solution {
public:
    bool dfs(vector<vector<int>>& graph , vector<int>& vis , vector<int>& par , int node , vector<int>& done)
    {
        if(done[node])
            return false;
        vis[node] = 1;
        done[node] = 1;
        for(auto x : graph[node])
        {
           
            if(vis[x])
                return true;
            else if(!vis[x])
            {
                par[x] = node;
                if(dfs(graph , vis , par , x , done))
                    return true;
            }
        }
         vis[node] = 0;
        return false;
    }
    bool canFinish(int num , vector<vector<int>>& p) {
        vector<vector<int>> graph(num);
        vector<int> done(num , 0);
        for(auto x : p)
        {
            graph[x[0]].push_back(x[1]);
            // graph[x[1]].push_back(x[0]);
        }
        
        
        for(auto x = 0 ; x < num;x++)
        {
            vector<int> vis(num , 0);
            vector<int> par(num , -1);
            if(!done[x])
            {
                if(dfs(graph , vis , par , x , done))
                {
                    return false;
                }
            }
        }
        cout<<endl;
        return true;
    }
};