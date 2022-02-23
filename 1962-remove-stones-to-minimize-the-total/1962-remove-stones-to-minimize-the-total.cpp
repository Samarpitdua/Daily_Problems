class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(auto x : piles)
            pq.push(x);
        while(!pq.empty() and k--)
        {
            int a = pq.top();
            pq.pop();
            if(a % 2)
                a++;
            a /= 2;
            if(a != 0)
                pq.push(a);
        }
        if(pq.empty())
            return 0;
        int ans = 0;
        while(!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};