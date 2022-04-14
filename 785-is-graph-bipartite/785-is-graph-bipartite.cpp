class Solution {
public:
    bool solve(vector<vector<int>>& graph , vector<int>& vis , vector<int>& colors , int node  , int color)
    {
        
        colors[node] = color;
        vis[node] = 1;
        for(auto child : graph[node])
        {
            if(!vis[child])
            {
                if(!solve(graph , vis , colors , child , 1 - color))
                    return false;
            }
            else
            {
                if(color == colors[child])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n , 0);
        vector<int> colors(n , -1);
        for(int i = 0 ; i < n ;i++)
        {
            if(!vis[i])
            {
                if(!solve(graph , vis , colors , i , 0))
                    return false;
            }
        }
        return true;
    }
};