class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans;
        for(int i = 0 ; i < n - 2 ; i++){
             vector<int> temp;
            for(int j = 0 ; j < m - 2 ; j++){
                int ans = 0;
                for(int k = i; k < (i + 3) ;k++){    
                    for(int l = j ; l < (j + 3) ;l++){
                        ans = max(ans , grid[k][l]);
                    }
                }
                temp.push_back(ans);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};