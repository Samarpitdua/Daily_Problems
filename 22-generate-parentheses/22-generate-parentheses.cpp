class Solution {
public:
    void solve(vector<string>& ans , int open , int close , string s)
    {
        if(open == 0 and close == 0)
        {
            ans.push_back(s);
            return;
        }
        if(close > 0)
            solve(ans , open  , close - 1 , s + ')');
        if(open > 0)
            solve(ans , open - 1, close + 1 , s + '(');
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(ans , n , 0 , "");
        return ans;
        
    }
};