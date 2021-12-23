class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>v(numCourses);
        vector<int>p;
        int n=numCourses;
        vector<int>indegree(n,0);
        for(auto pre:prerequisites)
        {
            int x=pre[0];
            int y=pre[1];
            v[x].push_back(y);
         //   v[y].push_back(x);
            indegree[y]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        int ct=0;
        stack<int>s;
        while(!q.empty())
        {
             ct++;
            int node=q.front();
            q.pop();
            s.push(node);
            for(auto child:v[node])
            {
                indegree[child]--;
                if(indegree[child]==0)
                    q.push(child);
            }
        }
        if(ct==n)
        {
            while(!s.empty())
            {
                p.push_back(s.top());s.pop();
            }
            return p;
        }
        else
        {
            return p;
        }
        
    }
};
