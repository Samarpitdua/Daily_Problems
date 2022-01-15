class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size() , ct = 0 , sum = 0 ,ans = 0;
      unordered_map<int,int>mp;
    
        for(int i = 0 ;i < n ;i++)
        {
            int p = 0;
            sum += nums[i];
            
            if(sum == k)
                ans++;
            if(mp[sum-k] > 0)
                ans += mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};