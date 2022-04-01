class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0;
        int start = 0 , end = height.size() - 1;
        while(start < end)
        {
            int curHeight = min(height[start] , height[end]);
            int curWater = abs(start - end) * curHeight;
            water = max(curWater , water);
            while(start < end and height[start] <= curHeight)
            {
                start++;
            }
            while(start < end and height[end] <= curHeight)
            {
                end--;
            }
                
        }
        return water;
    }
};