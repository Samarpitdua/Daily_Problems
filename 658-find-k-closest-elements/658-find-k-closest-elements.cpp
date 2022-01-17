class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int n = arr.size();
        priority_queue<pair<int , int >> pq;
        for(auto x1 : arr)
        {
            pq.push({abs(x - x1) , x1});
            if(pq.size() > k)
                pq.pop();
        }
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};