class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto x : stones)
            pq.push(x);
        while(pq.size() > 1){
            int temp = pq.top();
            pq.pop();
            int temp2 = pq.top();
            pq.pop();
            if(temp != temp2)
                pq.push(temp - temp2);
        }
        if(pq.empty())
            return 0;
        return pq.top();
    }
};