class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        map<int , int> mp;
        int ct = 0 , ans = 0;
        for(auto x : rolls){
            mp[x]++;
            if(mp[x] == 1)
                ct++;
            if(ct == k)
            {
                ans++;
                mp.clear();
                ct = 0;
            }
        }
        return ans + 1;
        
    }
};