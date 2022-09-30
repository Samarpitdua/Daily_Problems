class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        int cur = 0, cur_w, cur_h =-1,  n = buildings.size();
        priority_queue< pair<int, int>> liveBlg; // first: height, second: end time
        while(cur < n || !liveBlg.empty())
        { // if either some new building is not processed or live building queue is not empty
            cur_w= liveBlg.empty() ? buildings[cur][0]:liveBlg.top().second; // next timing point to process

            if(cur >= n || buildings[cur][0] > cur_w)
            { //first check if the current tallest building will end before the next timing point
                  // pop up the processed buildings, i.e. those  have height no larger than cur_H and end before the top one
                while(!liveBlg.empty() && ( liveBlg.top().second <= cur_w) ) 
                    liveBlg.pop();
            }
            else
            { // if the next new building starts before the top one ends, process the new building in the vector
                cur_w = buildings[cur][0];
                while(cur<n && buildings[cur][0]== cur_w)  // go through all the new buildings that starts at the same point
                {  // just push them in the queue
                    liveBlg.push({buildings[cur][2], buildings[cur][1]});
                    cur++;
                }
            }
            cur_h = liveBlg.empty() ? 0 : liveBlg.top().first;
            if(ans.empty() || (ans.back()[1] != cur_h) ) 
                ans.push_back({cur_w, cur_h});
        }
        return ans;
    }
};