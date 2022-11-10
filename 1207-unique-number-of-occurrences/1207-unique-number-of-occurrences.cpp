class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int , int> mp, mp2;
        for(auto x : arr)
            mp[x]++;
        for(auto x : mp)
        {
            mp2[x.second]++;
        }
        for(auto x : mp)
        {
            if(mp2[x.second] > 1)
                return false;
                
        }
        return true;
    }
};
