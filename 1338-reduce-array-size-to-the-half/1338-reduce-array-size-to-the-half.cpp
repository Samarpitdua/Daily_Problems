class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size() , ct = 0;
        int y = (n+1) / 2;
        map<int , int>mp;
        for(auto x : arr)
            mp[x]++;
        priority_queue<int> pq;
        for(auto x : mp)
            pq.push(x.second);
        while(y > 0)
        {
            int m = pq.top();
            y -= m;
            ct++;
            pq.pop();
        }
        return ct;
        
    }
};