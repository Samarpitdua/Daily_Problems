class Solution {
public:
    int minimumKeypresses(string s) {
        map<char, int> mp;
        for(auto x : s)
            mp[x]++;
        int ans = 0 , ct = 1;
        vector<int> v;
        for(auto x : mp)
        {
            v.push_back(x.second);
        }
        sort(v.begin(), v.end(), greater<int>());
        for(int i = 0 ; i < v.size() ;i++)
        {
            if(ct <= 9)
            {
                ans += v[i];
            }
            else if(ct <= 18)
                ans += (v[i] * 2);
            else
                ans += (v[i] * 3);
            ct++;
        }
        return ans;
    }
};