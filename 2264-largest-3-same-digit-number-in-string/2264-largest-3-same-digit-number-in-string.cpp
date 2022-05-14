class Solution {
public:
    string largestGoodInteger(string s) {
        int n = s.size();
        vector<int> ans;
        for(int i = 2 ; i < n ;i++)
        {
            if(s[i] == s[i - 1] and s[i - 1] == s[i - 2])
            {
                ans.push_back(s[i] - '0');
            }
        }
        if(ans.empty())
            return "";
        int maxi = *max_element(ans.begin() , ans.end());
        string st = to_string(maxi) + to_string(maxi) + to_string(maxi) ;
        return st;
    }
};