class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin() , nums.end());
        int start = 0;
        
        for(int i = 0 ; i < n ;i++)
        {
            if(nums[i] > 0)
                break;
            if(i != 0 and nums[i - 1] == nums[i])
                continue;
            
            int left = i + 1 , right = n - 1;
            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum < 0)
                    left++;
                else if(sum > 0)
                    right--;
                else
                {
                    ans.push_back({nums[i] , nums[left] , nums[right]});  
                    int val1 = nums[left] , val2 = nums[right];
                    while(left < right and nums[left] == val1)
                    {
                        left++;
                    }
                    while(left , right and nums[right] == val2)
                        right--;
                }
                
                    
            }
        }
        return ans;
    }
};