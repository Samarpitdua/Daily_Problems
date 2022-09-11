
class Solution {
public:
    // static bool comp(pair<int , int>& v , pair<int , int>& v2)
    // {
    //     if(v.second != v2.second)
    //     {
    //         return v.second > v2.second;
    //     }
    //     else
    //     {
    //         return v.first > v.second;
    //     }
    // }
    int minGroups(vector<vector<int>>& i) {
        sort(i.begin() , i.end());
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
        int ans = 0;
        for(auto x : i)
        {
            if(pq.empty())
                pq.push({x[1] , x[0]});
            else
            {
                int temp2 = pq.top().first;
                int temp1 = pq.top().second;
                pq.pop();
                if((x[0] < temp1 and x[1] < temp1) or (x[0] > temp2 and x[1] > temp2))
                {
                    pq.push({x[1] , x[0]});
                }
                else
                {
                    pq.push({temp2 , temp1});
                    pq.push({x[1] , x[0]});
                }
            }
            // ans = max(ans , pq.size());
        }
        return pq.size();
    }
};