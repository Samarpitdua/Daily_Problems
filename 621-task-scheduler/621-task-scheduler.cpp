#define pi pair<int , char>
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ct = 0;
        unordered_map<char , int>mp;
        for(auto x : tasks)
        {
            mp[x]++;
        }
        priority_queue<pi> pq , pq2;
        for(auto x : mp)
        {
            pq.push({x.second , x.first});
        }
        
        while(!pq.empty())
        {
            int a = pq.top().first;
            a--;
            char b = pq.top().second;
            if(a > 0)
                pq2.push({a , b});
            pq.pop();
            int temp = n;
            ct++;
            while(!pq.empty() and temp>0)
            {
                    int a = pq.top().first;
                    a--;
                    char b = pq.top().second;
                    if(a > 0)
                        pq2.push({a , b});
                    pq.pop();
                    temp--;
                    ct++;
            }
            if(pq.empty() and pq2.empty())
                break;
            if(temp > 0)
                ct += temp;
            
            while(!pq2.empty())
            {
                pq.push(pq2.top());
                pq2.pop();
            }
            cout<<ct<<" ";
        }
        return ct;
    }
};