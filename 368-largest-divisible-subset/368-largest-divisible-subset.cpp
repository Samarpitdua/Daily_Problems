class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n , 1);
        vector<vector<int>> v(n);
        sort(nums.begin() , nums.end());
        v[0].push_back(nums[0]);
        for(int i = 1 ; i < n ; i++)
        {
            int ans = 0 , temp = -1;
            for(int j = 0 ; j < i ; j++)
            {
                if(nums[i] % nums[j] == 0 or nums[j] % nums[i] == 0)
                {
                    if(dp[j] > ans)
                    {
                        ans = dp[j];
                        temp = j;
                    }
                }
            }
            if(temp != -1)
            {
                v[i] = v[temp];
            }
             v[i].push_back(nums[i]);   
            dp[i] = 1 + ans;
        }
        vector<int> y;
        for(auto x : v)
        {
            if(x.size() > y.size())
                y = x;
        }
        return y;
    }
};