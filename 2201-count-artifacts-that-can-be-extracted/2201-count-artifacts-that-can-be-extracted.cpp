class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        
        int ans = 0;
        vector<vector<int>> v(n + 1 , vector<int>(n + 1 , 0));
        for(auto x : dig)
        {
            v[x[0]][x[1]] = 1;
        }
        for(auto x : artifacts)
        {
            int p = 0;
            for(int i = x[0] ; i <= x[2] ; i++)
            {
                for(int j = x[1] ; j <= x[3] ;j++)
                {
                  //  cout<<i<<" "<<j<<endl;
                    if(!v[i][j])
                    {
                        p = 1;
                        break;
                    }
                }
                if(p)
                    break;
            }
                if(p == 0)
                    ans++;
        }
        return ans;
    }
};