class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& in) {
        sort(in.begin() , in.end());
        if(in.size() == 1)
            return 1;
        int start = in[0][0] , end = in[0][1];
        int ans = 1;
        for(int i = 1 ; i < in.size() ; i++)
        {
            if(in[i][0] <= start and in[i][1] >= end)
            {
                start = in[i][0];
                end = in[i][1];
                continue;
            }
            else if(in[i][1] >= start and in[i][1] <= end)
                continue;
            else
            {
                ans++;
                start = in[i][0];
                end = in[i][1];
            }
            
        }
        return ans;
    }
};