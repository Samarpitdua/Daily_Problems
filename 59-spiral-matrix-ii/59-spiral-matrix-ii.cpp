class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> ans(n , vector<int>(n , 0));
        int i = 0 , j = 0 , up = 0 , left = 0 , right = n - 1 , down = n - 1;
        int t = 1;
        while(1)
        {
            if(t > (n * n))
                break;
            i = up;
            j = left;
            while(j <= right)
            {
                ans[i][j++] = t++;
            }
            up += 1;
            i = up ;
            j = right;
            while(i <= down)
            {
                ans[i++][j] = t++;
            }
            
            right -= 1;
            i = down;
            j = right;
            while(j >= left)
            {
                ans[i][j--] = t++;
            }
            down--;
            i = down;
            j = left;
            while(i >= up)
            {
                ans[i--][j] = t++;
            }
            left++;
        }
        return ans;
    }
};