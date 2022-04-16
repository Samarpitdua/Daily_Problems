class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());
        
        int temp1 = intervals[0][0] , temp2 = intervals[0][1];
        vector<vector<int>> ans;
        for(auto x : intervals)
        {
            vector<int> tmp;
            {
                if(x[0] > temp2)
                {
                    tmp.push_back(temp1);
                    tmp.push_back(temp2);
                    ans.push_back(tmp);
                    temp1 = x[0];
                    temp2 = x[1];
                }
                else
                {
                    temp2 = max(temp2 , x[1]);
                }
            }
        }
        vector<int>v(2);
        v[0] = temp1;
        v[1] = temp2;
        ans.push_back(v);
        return ans ;
    }
};