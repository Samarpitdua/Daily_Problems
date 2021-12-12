class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int,int>mp;
        for(auto x: candyType)
        {
            mp[x]++;
        }
        int n = candyType.size();
        int  p = mp.size();
        int ans = min(n/2,p);
        return ans;
    }
};
