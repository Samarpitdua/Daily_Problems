class Solution {
public:
int timer=0; // to mark the first visiting time of the node
vector <int> adj[100005];
vector<vector<int>>ans;
void dfs(int node , vector<int>& in , vector<int> &low , int par , vector<bool>& vis)
{
    vis[node] = true;
    in[node] = low[node] = ++timer;
    for(int child : adj[node])
    {
    if(child == par)
        continue;
    if(vis[child] == 1)
    {
        low[node] = min(low[node] , in[child]);
    }
    else
    {
        dfs(child , in , low , node , vis);
        if(low[child]>in[node]) // condition for existence of bridge
        {
            ans.push_back({node,child});
    // cout<<node<<"-"<<child<<" is a bridge"<<endl;
        }
else
low[node]=min(low[node],low[child]); // update the low time of node after returning back
}
}
}
vector<vector<int>> criticalConnections(int n, vector<vector<int>>& c) {
    
    for(auto x : c)  // build graph 
    {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    vector<bool> vis(n + 1 , 0);
    vector<int> in(n , 0) , low(n , 0);
     dfs(0 , in , low , -1 , vis); 
    return ans;
}
};