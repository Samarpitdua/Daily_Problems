class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size() , m = matrix[0].size();
        int i = n - 1 , j = 0;
        while(i >= 0 and j < m){
            if(matrix[i][j] == target)
                return true;
            if(matrix[i][j] > target)
                i--;
            else
                j++;
        }
        return false;
    }
};