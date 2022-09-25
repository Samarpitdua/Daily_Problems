class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int , string>> v(n);
        for(int i = 0 ; i < n ;i++)
        {
            v[i]= {heights[i] , names[i]};
        }
        sort(v.begin(), v.end());
        vector<string> ans;
        for(auto x : v)
        {
            ans.push_back(x.second);
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};