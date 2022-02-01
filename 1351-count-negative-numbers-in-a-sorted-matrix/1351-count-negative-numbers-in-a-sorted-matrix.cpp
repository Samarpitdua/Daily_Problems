class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int r = 0 , l = cols - 1 , ans = 0;
        while( r < rows )
        {
            if(l >= 0 and grid[r][l] < 0 )
            {
                l--;
            }
            else
            {
                ans += (cols - l -1 );
                r++;
            }
        }
        return ans;
    }
};