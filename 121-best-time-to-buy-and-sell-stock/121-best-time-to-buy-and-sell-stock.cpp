class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() , temp = prices[0] , ans = 0;
        for(int i = 1 ; i < n ;i++)
        {
            ans = max(ans , prices[i] - temp);
            temp = min(temp , prices[i]);
        }
        return ans;
    }
};