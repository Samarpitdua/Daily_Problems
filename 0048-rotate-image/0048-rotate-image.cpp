class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int m = a.size() , n = a[0].size();
        
        for(int i = 0 ; i < m ; i++)
            for(int j = 0 ; j < i; j++)
                    swap(a[i][j] , a[j][i]);
    
        for(int i = 0 ; i < m ;i++)
            for(int j = 0 ; j < n / 2 ; j++)
                swap(a[i][j] , a[i][n - j - 1]);
    }
};