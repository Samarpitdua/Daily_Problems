class Solution {
public:
    void makeSet(vector<int>& parent)
    {
        for(int i=0;i<205;i++)
            parent[i]=i;
    }
    int findParent(int node,vector<int>& parent)
    {
        if(parent[node]==node)
            return node;
        else
            return parent[node]=findParent(parent[node],parent);
    }
    void combine(int u,int v,vector<int>& parent,vector<int>& rank)
    {
        u=findParent(u,parent);
        v=findParent(v,parent);
         if(rank[v]>rank[u])
            parent[u]=parent[v];   
        else if(rank[u]>rank[v])
            parent[v]=parent[u];
         else
             parent[u]=v,rank[v]++;
    }
    int findCircleNum(vector<vector<int>>& a) {
        vector<int> rank(205 , 0);
        vector<int> parent(205);
        makeSet(parent);
        int n = a.size();
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i + 1 ; j < n ; j++)
            {
                if(a[i][j] == 1)
                    combine(i , j , parent , rank);
            }
        }
        int ct=0;
        for(int i=0;i<a.size();i++)
        {
            if(i==parent[i])
                ct++;
        }
        return ct;
    }
};