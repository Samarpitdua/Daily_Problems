class Solution {
public:
    void dfs(vector<vector<int>>& ans ,vector<vector<int>>& graph , int node , vector<int> temp)
    {
    
        if(node == graph.size() - 1)
        {
            ans.push_back(temp);
            return;
        }
        for(auto x : graph[node])
        {
            temp.push_back(x);
            dfs(ans , graph , x , temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        int dest = n - 1;
        vector<int> vis(n , 0) , temp;
        temp.push_back(0);
            dfs(ans , graph , 0 , temp);
        return ans;
    }
};