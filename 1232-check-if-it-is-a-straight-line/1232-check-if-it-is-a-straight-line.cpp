class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        sort(c.begin() , c.end());
        if(c.size() == 1 or c.size() == 2)
        return true;
        int urp = 0;
        if(c[1][0] - c[0][0] == 0)
            urp = 1;
        double slope = (c[1][1] - c[0][1]) / (double)(c[1][0] - c[0][0]);
        // cout<<slope<<" ";
        for(int i = 2 ; i < c.size() ; i++)
        {
            if(urp)
            {
                if(c[i][0] - c[i - 1][0] == 0)
                    continue;
                else
                    return false;
            }
            double temp = (c[i][1] - c[i - 1][1]) / (double)(c[i][0] - c[i - 1][0]);
            if(temp == slope)
                continue;
            else
                return false;
        }
        return true;
    }
};