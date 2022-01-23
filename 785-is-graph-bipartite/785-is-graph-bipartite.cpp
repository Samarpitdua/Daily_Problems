class Solution {
public:
    bool check(vector<vector<int>>& graph ,vector<int>& vis , vector<int>& color , int col , int node)
    {
        if(color[node] == -1)
        {
            color[node] = col;
        }
        for(auto x : graph[node])
        {
            if(vis[x])
            {
                if(color[node] == color[x])
                    return false;
            }
            else
            {
                vis[x]=1;
                if(check(graph , vis , color ,1 - col , x) == false)
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n , 0);
        vector<int> color(n , -1);
        
        for(int i = 0 ; i < n ;i++)
        {
            if(!vis[i])
            {
                vis[i]=1;
                if(!check(graph , vis, color , 0 , i))
                    return false;
            }
        }
        return true;
    }
};