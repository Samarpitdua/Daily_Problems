class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int>st;
        int n = prices.size();
        vector<int>ans;
        for(int i = n - 1;i >= 0;)
        {
            if(st.empty())
            {
                ans.push_back(prices[i]);
                st.push(prices[i]);
                i--;
            }
            else
            {
                if(st.top() <= prices[i])
                {
                    ans.push_back(prices[i]-st.top());
                    st.push(prices[i]);
                    i--;
                }
                else
                {
                    st.pop();
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
