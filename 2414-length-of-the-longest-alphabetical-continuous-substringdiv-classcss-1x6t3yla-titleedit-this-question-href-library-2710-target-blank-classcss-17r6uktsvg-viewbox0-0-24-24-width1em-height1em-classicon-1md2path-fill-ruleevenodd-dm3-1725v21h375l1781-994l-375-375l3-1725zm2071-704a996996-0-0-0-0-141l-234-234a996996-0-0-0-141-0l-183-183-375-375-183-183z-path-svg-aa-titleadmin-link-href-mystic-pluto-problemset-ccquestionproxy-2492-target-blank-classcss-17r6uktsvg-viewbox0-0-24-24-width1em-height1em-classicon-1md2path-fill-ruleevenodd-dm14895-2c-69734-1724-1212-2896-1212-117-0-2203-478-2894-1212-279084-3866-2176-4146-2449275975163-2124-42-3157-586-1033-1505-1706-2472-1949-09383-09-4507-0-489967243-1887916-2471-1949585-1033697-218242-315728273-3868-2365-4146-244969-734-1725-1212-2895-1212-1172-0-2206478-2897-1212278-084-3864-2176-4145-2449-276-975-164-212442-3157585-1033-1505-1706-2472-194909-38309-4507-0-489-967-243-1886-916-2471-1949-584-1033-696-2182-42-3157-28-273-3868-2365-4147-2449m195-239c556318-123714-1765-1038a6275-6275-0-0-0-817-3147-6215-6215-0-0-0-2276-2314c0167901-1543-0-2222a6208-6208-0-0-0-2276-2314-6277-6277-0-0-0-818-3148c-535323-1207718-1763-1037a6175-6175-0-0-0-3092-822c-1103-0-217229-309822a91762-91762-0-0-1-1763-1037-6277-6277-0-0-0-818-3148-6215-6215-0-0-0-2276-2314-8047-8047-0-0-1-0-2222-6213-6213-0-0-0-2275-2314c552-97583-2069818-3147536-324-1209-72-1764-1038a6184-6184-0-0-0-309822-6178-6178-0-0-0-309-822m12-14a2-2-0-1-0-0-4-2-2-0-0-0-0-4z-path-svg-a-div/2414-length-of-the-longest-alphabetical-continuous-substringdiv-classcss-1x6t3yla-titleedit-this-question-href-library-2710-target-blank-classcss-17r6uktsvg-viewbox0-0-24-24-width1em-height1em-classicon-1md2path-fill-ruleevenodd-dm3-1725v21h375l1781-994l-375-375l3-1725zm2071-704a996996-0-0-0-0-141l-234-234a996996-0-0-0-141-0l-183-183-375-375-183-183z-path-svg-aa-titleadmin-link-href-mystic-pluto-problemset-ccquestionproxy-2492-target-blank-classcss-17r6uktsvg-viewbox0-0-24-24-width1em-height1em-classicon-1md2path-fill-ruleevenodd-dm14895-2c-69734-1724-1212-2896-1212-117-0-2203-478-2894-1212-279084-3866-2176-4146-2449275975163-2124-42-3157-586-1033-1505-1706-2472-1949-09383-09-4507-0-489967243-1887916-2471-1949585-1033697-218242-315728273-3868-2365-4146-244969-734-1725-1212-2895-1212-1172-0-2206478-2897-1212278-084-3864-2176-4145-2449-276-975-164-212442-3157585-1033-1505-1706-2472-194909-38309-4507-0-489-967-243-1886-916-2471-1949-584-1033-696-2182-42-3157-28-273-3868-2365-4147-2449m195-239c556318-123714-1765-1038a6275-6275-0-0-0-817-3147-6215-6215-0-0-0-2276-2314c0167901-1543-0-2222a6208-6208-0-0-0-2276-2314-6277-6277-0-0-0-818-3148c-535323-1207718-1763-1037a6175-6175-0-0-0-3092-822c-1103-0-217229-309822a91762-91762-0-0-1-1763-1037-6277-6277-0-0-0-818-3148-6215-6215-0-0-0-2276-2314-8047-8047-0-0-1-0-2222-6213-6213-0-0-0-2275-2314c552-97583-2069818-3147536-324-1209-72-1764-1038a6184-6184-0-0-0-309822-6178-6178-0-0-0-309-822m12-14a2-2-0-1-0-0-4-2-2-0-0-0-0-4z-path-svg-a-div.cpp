class Solution {
public:
    int longestContinuousSubstring(string s) {
        vector<int> v;
        int ans = 1 , ct = 1;
        for(auto x : s)
            v.push_back(x - 'a');
        for(int i = 0 ; i < v.size() - 1 ;i++)
        {
            if(v[i] + 1 == v[i + 1])
            {
                ct++;
            }
            else
                ct = 1;
            ans = max(ans , ct);
        }
        return ans;
    }
};