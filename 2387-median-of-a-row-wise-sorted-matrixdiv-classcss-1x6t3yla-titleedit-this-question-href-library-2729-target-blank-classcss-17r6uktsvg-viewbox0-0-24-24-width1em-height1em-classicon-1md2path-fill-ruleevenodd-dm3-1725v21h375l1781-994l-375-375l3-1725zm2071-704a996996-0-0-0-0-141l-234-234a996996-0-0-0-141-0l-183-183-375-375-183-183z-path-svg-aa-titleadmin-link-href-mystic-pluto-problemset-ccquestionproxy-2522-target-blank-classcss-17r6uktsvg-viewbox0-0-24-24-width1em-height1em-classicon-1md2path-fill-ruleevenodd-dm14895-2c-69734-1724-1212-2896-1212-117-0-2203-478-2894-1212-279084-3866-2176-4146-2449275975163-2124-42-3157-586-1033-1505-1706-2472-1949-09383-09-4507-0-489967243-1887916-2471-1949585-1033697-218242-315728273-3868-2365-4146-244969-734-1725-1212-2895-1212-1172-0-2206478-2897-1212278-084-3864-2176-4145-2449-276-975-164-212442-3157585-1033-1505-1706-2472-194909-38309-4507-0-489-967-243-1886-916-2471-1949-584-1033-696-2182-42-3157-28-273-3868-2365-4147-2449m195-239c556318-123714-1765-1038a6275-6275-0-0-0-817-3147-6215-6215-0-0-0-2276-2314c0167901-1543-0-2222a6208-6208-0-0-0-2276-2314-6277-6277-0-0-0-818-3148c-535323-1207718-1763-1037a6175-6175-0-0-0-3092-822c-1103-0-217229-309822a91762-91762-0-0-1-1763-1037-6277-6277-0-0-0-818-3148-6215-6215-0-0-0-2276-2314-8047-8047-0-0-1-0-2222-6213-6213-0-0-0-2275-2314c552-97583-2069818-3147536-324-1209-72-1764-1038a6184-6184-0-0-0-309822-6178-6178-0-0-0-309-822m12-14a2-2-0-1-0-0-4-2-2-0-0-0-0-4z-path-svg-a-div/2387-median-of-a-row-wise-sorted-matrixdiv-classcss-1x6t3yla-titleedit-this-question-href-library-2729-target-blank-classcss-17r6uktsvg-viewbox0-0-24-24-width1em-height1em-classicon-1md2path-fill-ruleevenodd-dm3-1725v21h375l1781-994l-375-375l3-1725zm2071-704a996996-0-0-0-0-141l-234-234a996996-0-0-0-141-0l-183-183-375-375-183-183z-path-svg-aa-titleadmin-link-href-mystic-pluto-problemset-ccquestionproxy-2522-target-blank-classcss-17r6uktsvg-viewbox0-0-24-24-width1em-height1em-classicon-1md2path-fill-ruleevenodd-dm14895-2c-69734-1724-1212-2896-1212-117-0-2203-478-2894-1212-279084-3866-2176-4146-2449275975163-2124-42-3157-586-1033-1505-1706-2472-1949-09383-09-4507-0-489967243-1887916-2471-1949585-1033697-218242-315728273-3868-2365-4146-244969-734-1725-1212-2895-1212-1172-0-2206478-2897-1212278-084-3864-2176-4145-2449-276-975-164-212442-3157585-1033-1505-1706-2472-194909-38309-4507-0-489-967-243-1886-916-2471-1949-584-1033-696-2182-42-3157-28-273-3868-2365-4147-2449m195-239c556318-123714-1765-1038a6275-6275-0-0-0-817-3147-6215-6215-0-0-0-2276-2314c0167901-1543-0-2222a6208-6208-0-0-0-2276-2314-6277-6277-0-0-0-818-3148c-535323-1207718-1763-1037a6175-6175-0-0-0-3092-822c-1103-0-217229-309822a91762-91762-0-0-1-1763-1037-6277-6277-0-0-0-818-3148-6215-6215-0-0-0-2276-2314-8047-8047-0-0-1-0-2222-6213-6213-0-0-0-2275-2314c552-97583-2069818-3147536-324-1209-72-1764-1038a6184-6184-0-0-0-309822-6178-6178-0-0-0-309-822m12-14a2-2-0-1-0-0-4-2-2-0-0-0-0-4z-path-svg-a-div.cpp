class Solution {
public:
    int getCount(vector<vector<int>>& grid , int i , int mid)
    {
        auto x =  upper_bound(grid[i].begin() , grid[i].end() , mid) - grid[i].begin() ;
        return x;
    }
    int matrixMedian(vector<vector<int>>& grid) {
        int low = 0 , high = 1e7;
        int n = grid.size() , m = grid[0].size();
        int f = (m * n) / 2;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int ct = 0;
            for(int i = 0 ; i < n ;i++)
            {
                ct += getCount(grid , i , mid);
            }
            if(ct <= f)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};