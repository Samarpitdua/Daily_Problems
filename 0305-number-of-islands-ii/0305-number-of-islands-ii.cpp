class DisJointSet
{
    vector<int> size, parent;
    public:
    DisJointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1);
        for(int i = 0 ;i <= n ;i++)
            parent[i] = i , size[i] = 1;
    }
    int findPar(int node)
    {
        if(node == parent[node])
            return node;
        else 
            return parent[node] = findPar(parent[node]);
    }
    void unionBySize(int u , int v)
    {
        int uPar = findPar(u);
        int vPar = findPar(v);
        if(uPar == vPar)
            return;
        if(size[uPar] >= size[vPar])
        {
            parent[vPar] = uPar;
            size[uPar] += size[vPar];
        }
        else
        {
            parent[uPar] = vPar;
            size[vPar] += size[uPar];
        }
    }
    
};
bool valid(int adjr , int adjc , int m , int n)
{
    return (adjr >= 0 and adjc >=0 and adjr <m and adjc < n);
}
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        DisJointSet ds(m * n);
        vector<vector<int>> vis(m , vector<int>(n , 0));
        int ct = 0;
        vector<int> ans;
        for(auto x : positions)
        {
            int row = x[0] , col = x[1];
            if(vis[row][col] == 1)
            {
                ans.push_back(ct);
                continue;
            }
            vis[row][col] = 1;
            ct++;
            
            int dr[] = {0 , 0 , -1 , 1};
            int dc[] = {-1 , 1 , 0 , 0};
            for(int i = 0 ; i <= 3 ;i++)
            {
                int adjr = row + dr[i];
                int adjc = col + dc[i];
                if(valid(adjr , adjc , m , n))
                {
                    if(vis[adjr][adjc])
                    {
                        int node = row * n + col;
                        int adjnode = adjr * n + adjc;
                        if(ds.findPar(node) != ds.findPar(adjnode))
                        {
                            ct--;
                            ds.unionBySize(node, adjnode);
                        }
                    }
                }
            }
            ans.push_back(ct);
        }
        return ans;
    }
    
};