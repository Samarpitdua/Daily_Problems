class NumMatrix {
public:
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size() , n = matrix[0].size();
        sum.resize(m , vector<int>(n , 0));
        int sum2;
        for(int i = 0 ; i < m ;i++)
        {
            sum2 = 0;
            for(int j = 0 ; j < n ;j++)
            {
                sum2 += matrix[i][j];
                sum[i][j] = sum2;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        int temp;
        for(int i = row1 ;i <= row2 ;i++)
        {
            if(col1 == 0)
                temp = 0;
            else
                temp = sum[i][col1 - 1];
            ans += (sum[i][col2] - temp);
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */