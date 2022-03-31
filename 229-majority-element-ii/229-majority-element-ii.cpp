class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int x = -1, y  = -1, ct1 = 0 , ct2 = 0 , n = nums.size();
        if(n == 1)
            return nums;
        vector<int> ans;
        for(int i = 0 ; i < n ;i++)
        {
            
            if(nums[i] == x)
            {
                ct1++;
            }
            else if(nums[i] == y)
                ct2++;
            else if(ct1 == 0)
            {
                x = nums[i];
                ct1++;
            }
            else if(ct2 == 0)
            {
                y = nums[i];
                ct2++;
            }
            else
                ct1-- , ct2--;
        }
        
        ct1 = ct2 = 0;
        
        for(int i = 0 ; i < n ;i++)
        {
            if(nums[i] == x)
                ct1++;
            else if(nums[i] == y)
                ct2++;
        }
        if(ct1 > (n / 3))
        {
            ans.push_back(x);
        }
        if(ct2 > (n / 3))
        {
            ans.push_back(y);
        }
        return ans;
    }
};