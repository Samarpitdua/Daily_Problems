class Solution {
public:
    unordered_map<string , vector<pair<string , double>> > graph;
        unordered_map<string , bool> vis;
    double queryAns;
    bool dfs(string startNode, string endNode, double runningProduct)
    {
        
        if(startNode == endNode and graph.find(startNode) != graph.end()) 
        {
            queryAns = runningProduct;
            return true;    
        }
        
        bool tempAns = false;
        vis[startNode] = true;
        
        for(int i = 0; i < graph[startNode].size(); i++){
            if(!vis[graph[startNode][i].first])
            {
                tempAns = dfs(graph[startNode][i].first, endNode, runningProduct * graph[startNode][i].second);
                if(tempAns)
                {
                    break;
                }
            }
        }
        
        vis[startNode] = false;
        return tempAns;
        
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        
        for(int i = 0 ; i < equations.size() ;i++)
        {
            graph[equations[i][0]].push_back({equations[i][1] , values[i]});
            graph[equations[i][1]].push_back({equations[i][0] , 1 / (double)values[i]});
            vis[equations[i][1]] = false;
            vis[equations[i][0]] = false;
        }
        vector<double> ans;
        for(auto x : queries)
        {
            queryAns = 1;
           if(dfs(x[0] , x[1] , 1))
           {
               ans.push_back(queryAns);
           }
            else 
            {
                ans.push_back(-1);
            }
        }
        return ans;
        
    }
};