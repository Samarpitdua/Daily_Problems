class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        long long int n = heights.size() , ans = -1;
        priority_queue<long long int> pq;
        for(int i = 1 ; i < n ;)
        {
            if(heights[i] < heights[i - 1])
            {
                i++;
                continue;
            }
            long long int diff = heights[i] - heights[i - 1];
            pq.push(diff);
            bricks -= diff;
            if(bricks >= 0)
                i++;
            else
            {
                    if(ladders)
                    {
                        ladders--;
                        bricks += pq.top();
                        pq.pop();
                        i++;
                        continue;
                    }
                    else
                    {
                        return i - 1;
                    }
                }
        }
        return n - 1;
    }
};