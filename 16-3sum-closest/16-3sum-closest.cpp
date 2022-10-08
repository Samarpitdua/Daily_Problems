class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int diff = INT_MAX;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i + 1 , k = n - 1 ; j < k ;)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < target)
                {
                    j++;
                }
                else
                    k--;
                if(abs(diff) > abs(target-sum))
                    diff = target - sum;
                if(!diff)
                    return target;
            }
        }
        return target - diff;
    
        
    }
};