class Solution {
public:
    void solve(vector<long long>& v)
    {
        long long ct = 0;
        for(int i = 1 ; i <= 9 ;i++)
        {
            ct = 0;
            for(int j = i;j <= 9;j++)
            {
                ct *= 10;
                ct += j;
                v.push_back(ct);
            }
                
        }
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        vector<long long>v;
        solve(v);
        for(auto x : v)
        {
            if(x >= low and x <= high)
            {
                ans.push_back(x);
            }
        }
        sort(ans.begin() ,ans.end());
        return ans;
        
    }
};