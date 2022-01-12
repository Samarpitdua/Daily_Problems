class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long ans = 0 , ct = 1;
        for(int i = 1 ; i < n ; i++)
        {
            if(prices[i - 1] - prices[i] == 1)
                ct++;
            else
            {
                ans += (ct * (ct + 1)) / 2;
                ct = 1;
            }
        }
        ans += (ct * (ct + 1)) / 2;
        return ans;
        
    }
};