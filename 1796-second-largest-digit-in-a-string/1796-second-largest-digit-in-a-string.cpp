class Solution {
public:
    int secondHighest(string s) {
        int maxi = 0;
        priority_queue<int ,vector<int> , greater<int> > pq;
        map<int , int>mp;
        for(auto x : s)
        {
            if(x >= '0' and x <='9')
            {
                int temp= x - '0';
                if(!mp[x])
                    mp[x]++ , pq.push(temp);
            }
            if(pq.size() > 2)
                pq.pop();
        }
        if(!pq.size() or pq.size() == 1)
            return -1;
        else
            return pq.top();
        
    }
};