class Solution {
public:
    string convert(string s, int n) {
        vector<string> v(n);
        string ans;
        int ct = 0;
        int p = s.size();
        if(n == 1)
            return s;
        for(int i = 0 ; i < p ;)
        {
            while(i < p and ct < n)
                v[ct++].push_back(s[i++]);
            if(i == p)
                break;
            ct -= 2;
            while(i < p and ct >= 0)
                v[ct--].push_back(s[i++]);
            if(i == p)
                break;
            ct += 2;
        }
        for(auto x : v)ans += x;
        return ans;
    }
};