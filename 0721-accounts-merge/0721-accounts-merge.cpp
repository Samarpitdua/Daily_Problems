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
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        sort(accounts.begin() , accounts.end());
        int n= accounts.size();
        DisJointSet ds(n);
        unordered_map<string , int> mp;
        vector<vector<string>> ans;
        
        for(int i = 0 ; i < accounts.size() ;i++)
        {
            for(int j = 1 ; j < accounts[i].size() ;j++)
            {
                if(mp.find(accounts[i][j]) == mp.end())
                {
                    mp[accounts[i][j]] = i;
                }
                else
                {
                    ds.unionBySize(i , mp[accounts[i][j]]);
                }
            }
        }
        
        vector<string> merge[n];
        for(auto x : mp)
        {
            string node = x.first;
            int papa = ds.findPar(x.second);
            merge[papa].push_back(node);
        }
        for(int i = 0 ; i < n ;i++)
        {
            if(merge[i].size() == 0)
                continue;
            else
            {
                sort(merge[i].begin() , merge[i].end());
                vector<string> temp;
                temp.push_back(accounts[i][0]);
                for(auto x : merge[i])
                    temp.push_back(x);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};