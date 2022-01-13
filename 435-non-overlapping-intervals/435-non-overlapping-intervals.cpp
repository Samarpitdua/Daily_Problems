class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int p = -1 , temp , ct = 0;
        sort(intervals.begin() , intervals.end());
        for(auto x : intervals)
        {
            if(p == -1)
            {
                temp = x[1];
                p = 1; 
            }
            else
            {
                if(x[0] >= temp)
                    temp = x[1];
              
                else
                {
                    ct++;
                    if(x[1] < temp)
                    {
                        temp = x[1];
                    }
                }
            }
        }
        return ct;
    }
};