class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& p) {
         vector<vector<int>> graph(num);
        vector<int> indegree(num , 0);
        for(auto x : p)
        {
            graph[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }
        queue<int> q;
        int ct = 0;
        vector<int> ans;
        for(int i = 0 ; i < num ; i++)
        {
            if(indegree[i] == 0)
                ct++ , q.push(i) , ans.push_back(i);
        }
        while(!q.empty())
        {
            int temp = q.front();
            q.pop();
            for(auto x: graph[temp])
            {
                indegree[x]--;
                if(indegree[x] == 0)
                {
                    ct++;
                    q.push(x);
                    ans.push_back(x);
                }
            }
        }
        if(ct == num)
            reverse(ans.begin() , ans.end());
        else
            ans.clear();
        return ans;
        
    }
};