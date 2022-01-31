class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int m = a.size();
        int n = a[0].size();
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < i; j++)
            {
                if(i == j)
                    continue;
                else
                    swap(a[i][j] , a[j][i]);
            }
        }
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 , k = m - 1 ; j < k ; j++ , k--)
            {
                swap(a[i][j] , a[i][k]);
            }
        }
          
        
    }
};