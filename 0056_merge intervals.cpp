class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int temp=-1,ans1=-1;
        vector<vector<int>> ans;
        for(auto x:intervals)
        {
            int y = x[0];
            int z = x[1];
            if(temp == -1)
            {
                ans1 = y;
                temp = z ;
                continue;
            }
            else if(y>temp)
            {
                vector<int>v(2);
                v[0]=ans1;
                v[1]=temp;
                ans.push_back(v);
                ans1=y;
                temp=z;
                continue;
            }
            else
            {
                temp = max(z,temp);
                continue;
            }
                
        }
        vector<int>v(2);
                v[0]=ans1;
                v[1]=temp;
                ans.push_back(v);
        return ans ;
        
    }
};
