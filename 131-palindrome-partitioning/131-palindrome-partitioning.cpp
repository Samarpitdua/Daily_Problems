class Solution {
public:
    bool isPallindrome(string s)
    {
        int n = s.size();
        int i = 0 , j = n - 1;
        while(i < j)
        {
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }
    void solve(vector<vector<string>>& ans , vector<string> temp , string s , int ind , int n)
    {
        if(ind == n)
        {
            ans.push_back(temp);
            return;
        }
        for(int i = ind ; i < n ; i++)
        {
            string curr = s.substr(ind , i - ind + 1);
            if(isPallindrome(curr))
            {
                temp.push_back(curr);
                solve(ans , temp , s , i + 1 , n);
                temp.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(ans , temp , s , 0 , s.size());
        return ans;
    }
};