class Solution {
public:
    int minDeletions(string s) {
        map<char , int> mp;
        for(auto x : s){
            mp[x]++;
        }
        vector<int> v;
        for(auto x : mp){
            v.push_back(x.second);
        }
        sort(v.begin() , v.end() , greater<int>());
        int f = v[0];
        int ans = 0;
        for(auto x : v) {
            if(x > f) 
            {
                if(f > 0)
                    ans += (x - f); 
                else 
                    ans += x;
            }
            f=min(f - 1 , x - 1); 
        }
        return ans;
    }
};