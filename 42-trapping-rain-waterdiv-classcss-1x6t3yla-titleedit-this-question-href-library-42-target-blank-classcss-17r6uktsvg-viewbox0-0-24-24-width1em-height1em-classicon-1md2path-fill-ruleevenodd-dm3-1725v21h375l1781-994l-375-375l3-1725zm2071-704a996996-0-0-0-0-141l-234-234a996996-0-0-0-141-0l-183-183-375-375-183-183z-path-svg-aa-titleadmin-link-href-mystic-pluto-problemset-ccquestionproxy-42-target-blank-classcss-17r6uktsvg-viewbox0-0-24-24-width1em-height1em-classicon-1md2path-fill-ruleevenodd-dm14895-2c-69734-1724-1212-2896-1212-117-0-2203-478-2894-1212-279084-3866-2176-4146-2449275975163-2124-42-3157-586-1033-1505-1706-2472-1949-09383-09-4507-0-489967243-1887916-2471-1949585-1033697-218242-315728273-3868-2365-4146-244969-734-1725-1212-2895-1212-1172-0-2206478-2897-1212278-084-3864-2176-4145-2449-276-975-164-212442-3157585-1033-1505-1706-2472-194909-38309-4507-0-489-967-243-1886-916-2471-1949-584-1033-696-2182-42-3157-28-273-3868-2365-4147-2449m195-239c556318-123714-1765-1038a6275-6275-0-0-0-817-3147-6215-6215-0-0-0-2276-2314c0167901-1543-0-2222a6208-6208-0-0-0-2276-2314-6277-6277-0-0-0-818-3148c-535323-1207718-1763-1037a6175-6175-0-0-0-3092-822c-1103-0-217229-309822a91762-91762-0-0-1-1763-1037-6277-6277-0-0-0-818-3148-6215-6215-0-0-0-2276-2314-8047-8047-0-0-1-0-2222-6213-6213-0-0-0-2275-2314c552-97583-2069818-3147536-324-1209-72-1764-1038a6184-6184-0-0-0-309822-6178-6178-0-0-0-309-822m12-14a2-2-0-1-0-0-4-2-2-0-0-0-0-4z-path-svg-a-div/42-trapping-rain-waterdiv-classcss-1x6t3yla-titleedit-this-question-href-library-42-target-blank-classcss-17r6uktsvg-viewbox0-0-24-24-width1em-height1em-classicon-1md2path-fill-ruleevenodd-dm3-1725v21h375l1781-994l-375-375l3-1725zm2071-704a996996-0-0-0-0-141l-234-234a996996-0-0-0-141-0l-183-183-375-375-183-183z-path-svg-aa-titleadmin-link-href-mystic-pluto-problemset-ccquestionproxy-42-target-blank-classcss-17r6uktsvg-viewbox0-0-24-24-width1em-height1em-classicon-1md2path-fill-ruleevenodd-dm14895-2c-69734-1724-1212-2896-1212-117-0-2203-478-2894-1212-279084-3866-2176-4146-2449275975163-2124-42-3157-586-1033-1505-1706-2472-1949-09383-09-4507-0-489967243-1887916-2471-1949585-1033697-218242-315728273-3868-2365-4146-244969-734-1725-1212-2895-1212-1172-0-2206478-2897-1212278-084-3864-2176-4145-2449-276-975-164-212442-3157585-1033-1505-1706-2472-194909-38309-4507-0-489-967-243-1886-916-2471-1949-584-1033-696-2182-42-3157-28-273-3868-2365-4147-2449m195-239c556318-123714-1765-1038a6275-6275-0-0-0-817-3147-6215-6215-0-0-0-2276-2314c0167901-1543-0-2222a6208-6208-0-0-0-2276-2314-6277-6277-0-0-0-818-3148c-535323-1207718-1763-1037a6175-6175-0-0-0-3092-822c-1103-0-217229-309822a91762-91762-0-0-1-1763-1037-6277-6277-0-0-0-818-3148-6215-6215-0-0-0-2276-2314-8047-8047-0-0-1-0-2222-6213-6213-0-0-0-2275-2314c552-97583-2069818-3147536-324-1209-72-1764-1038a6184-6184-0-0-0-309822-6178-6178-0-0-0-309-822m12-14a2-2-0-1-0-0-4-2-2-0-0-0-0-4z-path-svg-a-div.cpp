class Solution {
public:
    int trap(vector<int>& height) {
         int n = height.size();
        int l = 0 , r = n - 1 , ans = 0;
        int maxil = 0 , maxir = 0;
        while(l < r)
        {
            if(height[l] < height[r])
            {
                if(height[l] <= maxil)
                {
                    ans += (maxil - height[l]);
                }
                else
                    maxil = height[l];
                l++;
            }
            else
            {
                 if(height[r] <= maxir)
                {
                    ans += (maxir - height[r]);
                }
                else
                    maxir = height[r];
                r--;
            }
        }
        return ans;
    }
};