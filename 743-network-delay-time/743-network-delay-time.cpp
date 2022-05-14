typedef pair<int,int>pi;
class Solution {
public:
    //USING BELLMAN-FORD ALGORITHM
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
     vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        for(int i = 0 ; i < n; i++)
        {
            for(auto edge:times)
            {
                int u=edge[0],v=edge[1],w=edge[2];
                if(dist[u]!=INT_MAX and dist[v]>dist[u]+w)
                    dist[v]=dist[u]+w;
            }
        }
        int ans =  *max_element(dist.begin() + 1 , dist.end());
        if(ans == INT_MAX)
            return -1;
        return ans;
    }
};