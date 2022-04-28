class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int ans = INT_MIN;
        priority_queue<pair<int , int>> pq;
        pq.push({points[0][1] - points[0][0] , points[0][0]});
        
        for(int i = 1 ; i < points.size() ;i++)
        {
            int x = points[i][0] , y = points[i][1];
            while(!pq.empty() and (x - pq.top().second ) > k)
            {
                pq.pop();
            }
            if(!pq.empty())
            {
                ans = max(ans , x + y + pq.top().first);
            }
            pq.push({y - x , x});
            cout<<ans<<" ";
        }
        return ans;
        
        
    }
};