class Solution {
public:
    
    //In below approach we solved the question in time comp. : O(n) and space complexity : O(n)
    int trap(vector<int>& height) {
        int ans = 0 , n = height.size() , maxil = 0 , maxir = 0;
        vector<int> maxL(n , 0) , maxR(n , 0);
        for(int i = 0 ; i < height.size() ;i++)
        {
            maxL[i] = maxil;
            if(height[i] > maxil)
                maxil = height[i];
                
        }
        for(int i = n - 1 ; i >= 0 ;i--)
        {
            maxR[i] = maxir;
            if(height[i] > maxir)
                maxir = height[i];
                
        }
        for(int i = 0 ; i < n ;i++)
        {
            int temp = min(maxL[i] , maxR[i]) - height[i];
            if(temp >= 0)
                ans += temp;
        }
        return ans;
        
        
    }
};