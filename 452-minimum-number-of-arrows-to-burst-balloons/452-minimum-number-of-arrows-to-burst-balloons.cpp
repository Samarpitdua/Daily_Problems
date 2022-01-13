class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ct = 0 , p = -1 , temp ;
        sort(points.begin() , points.end());
        for(auto x : points)
        {
                if(p == -1)
                {
                    temp = x[1];
                    p = 1;
                    ct++;
                    continue;
                }
                else
                {
                    if(x[0] <= temp)
                    {
                        temp = min(temp , x[1]);
                        continue;
                    }
                    else
                    {
                        temp = x[1];
                        ct++;
                        continue;
                    }
                }
        }
        return ct;
        
    }
};