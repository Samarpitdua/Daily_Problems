class Solution {
public:
    void dfs(int i , vector<int>& vis , vector<int> graph[]){
        vis[i] = 1;
        for(auto x : graph[i])
            if(!vis[x]) dfs(x , vis, graph);
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> graph[n] , vis(n , 0);
        for(auto x : edges)graph[x[0]].push_back(x[1]) , graph[x[1]].push_back(x[0]);
        int ct = 0;
        for(int i = 0 ; i < n ;i++)
            if(!vis[i])ct++, dfs(i , vis , graph);
        return ct;
    }
};