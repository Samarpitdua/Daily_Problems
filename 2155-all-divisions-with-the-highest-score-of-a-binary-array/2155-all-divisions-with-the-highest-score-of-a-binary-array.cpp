class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size() , maxi = 0 ,one(0) , zero(0);
        vector<int> left(n + 1, 0) , right(n + 1 , 0) , ans;
        for(int i = 0 ; i < n ;i++)
        {
            left[i] = zero;
            if(nums[i] == 0)
                zero++;
        }
        left[n] = zero;
        for(int i = n - 1 ; i >= 0 ;i--)
        {
            if(nums[i] == 1)
                one++;
            right[i] = one;
        }
        for(int i = 0 ; i <= n ;i++)
        {
            if(left[i] + right[i] > maxi)
                maxi = left[i] + right[i];
        }
        for(int i = 0 ; i <= n ;i++)
        {
            if(left[i] + right[i] == maxi)
                ans.push_back(i);
        }
        return ans;
        
        
        
    }
};