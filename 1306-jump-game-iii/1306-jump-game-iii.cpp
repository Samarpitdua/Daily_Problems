class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n , 0);
        queue<int> q;
        q.push(start);
        while(!q.empty())
        {
            int temp = q.front();
            q.pop();
            int a = temp + arr[temp];
            int b = temp - arr[temp];
            if(a >= 0 and a < n)
            {
                if(!vis[a])
                {
                    vis[a] = 1;
                    if(arr[a] == 0)
                        return true;
                    else
                        q.push(a);
                }
            }
            if(b >= 0 and b < n)
            {
                if(!vis[b])
                {
                    vis[b] = 1;
                    if(arr[b] == 0)
                        return true;
                    else
                        q.push(b);
                }
            }
        }
        return false;
    }
};