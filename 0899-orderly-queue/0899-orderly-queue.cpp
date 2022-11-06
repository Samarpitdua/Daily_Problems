class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k > 1) 
        {
            sort(s.begin(), s.end());
            return s;
        }
        
        int n = s.size();
        string ans = s;
        s += s;
        for(int i = 0 ; i < n ; i++) {
            if(s.substr(i, n) < ans)
                ans = s.substr(i, n);
        }
        return ans;
    }
};