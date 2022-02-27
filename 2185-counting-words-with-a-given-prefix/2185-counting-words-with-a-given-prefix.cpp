class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for(auto x : words)
        {
            if(x.find(pref) == 0)
                ans++;
        }
        return ans;
        
    }
};