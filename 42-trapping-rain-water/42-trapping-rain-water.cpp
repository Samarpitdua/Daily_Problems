class Solution {
public:
    //2nd approach
    //Time complexity : O(n)
    //Space complexity : o(1)
    //We will use two pointer approach
    int trap(vector<int>& height) {
        int ans = 0 , n = height.size() , maxil = 0 , maxir = 0;
        int left = 0 , right = n - 1;
        while(left < right)
        {
            if(height[left] <= height[right])
            {
                if(height[left] < maxil)
                {
                    ans += maxil - height[left];
                }
                else
                    maxil = height[left];
                left++;
            }
            else
            {
                if(height[right] < maxir)
                {
                    ans += maxir - height[right];
                }
                else
                    maxir = height[right];
                right--;
            }
        }
        return ans;
        
        
    }
};