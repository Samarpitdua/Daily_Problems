class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        int n = nums.size();
        for(auto y : nums)
            sum += y;
        if(sum == x)
            return n;
        sum -= x;
        // cout<<sum<<" ";
        int temp = 0;
        int ans = -1;
        int i = 0 , j = 0;
        for(; i< n and j < n;)
        {
            
            if(temp == sum)
            {
                ans = max(ans , j - i);
                temp -= nums[i];
                i++;
            }
            else if(temp < sum)
            {
                temp += nums[j];
                j++;
            }
            else
            {
                temp -= nums[i];
                i++;
            }
            // cout<<ans<<" ";
        }
        while(i < n and temp >= sum)
        {
            if(temp == sum)
                ans = max(ans , j - i);
            temp -= nums[i];
            i++;
        }
        if(ans == -1)
            return ans;
        else
        {
            return (n - ans);
        }
        
    }
};
