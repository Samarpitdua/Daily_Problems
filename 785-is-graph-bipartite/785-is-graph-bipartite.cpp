class Solution {
public:
    bool solve2(vector<vector<int>>& graph , vector<int>& vis , vector<int>& colors , int node  , int color)
    {
        queue<int> q;
        q.push(node);
        vis[node] = 1;
        colors[node] = color;
        while(!q.empty())
        {
            int temp = q.front();
            int sz = q.size();
            q.pop();
            for(auto child : graph[temp])
            {
                if(!vis[child])
                {
                    vis[child] = 1;
                    colors[child] = 1 - colors[temp];
                    q.push(child);           
                }
                else
                {
                    if(colors[temp] == colors[child])
                        return false;
                }
            }
            
        }
        return true;
    }
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
                if(!solve2(graph , vis , colors , i , 0))
                    return false;
            }
        }
        return true;
    }
};