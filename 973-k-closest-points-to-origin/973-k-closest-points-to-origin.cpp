#define pi pair<int,pair<int,int>>
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pi>pq;
        for(auto x : points)
        {
            int diff = x[0] * x[0] + x[1] * x[1];
            pq.push({diff , {x[0] , x[1]}});
            if(pq.size() > k)
                pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty())
        {
            vector<int> temp;
            temp.push_back(pq.top().second.first);
            temp.push_back(pq.top().second.second);
            ans.push_back(temp);
            pq.pop();
        }
        return ans;
        
    }
};