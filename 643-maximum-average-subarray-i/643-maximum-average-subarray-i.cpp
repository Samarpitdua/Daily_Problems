class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size() ;
        double maxi = INT_MIN;
        int ans = 0;
        
        for(int i = 0  , j = 0; i < n and  j < n;)
        {
            if(j < k - 1)
            {
                ans += nums[j];
                j++;
            }
            else
            {
                ans += nums[j];
                double avg = ans / double(k);
                maxi = max(maxi , avg);
                ans -= nums[i];
                i++;
                j++;
            }
          //  cout<<maxi<<" ";
        }
        
        return maxi;
        
    }
};