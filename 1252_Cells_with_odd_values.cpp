class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>>a(m,vector<int>(n,0));
        for(auto x:indices)
        {
            int c=x[0];
            int d=x[1];
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i==c and j==d)
                    {
                        a[i][j]+=2;
                    }
                    else if(i==c or j==d)
                    {
                        a[i][j]++;
                    }
                }
            }
        }
        int ct=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
               // cout<<a[i][j]<<" ";
                if(a[i][j]&1)
                    ct++;
            }
            cout<<"\n";
        }
        return ct;
    }
};
