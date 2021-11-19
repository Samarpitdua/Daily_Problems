class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<char,int>mp;int ct=0;
        for(int i=0;i<jewels.size();i++)
            mp[jewels[i]]++;
        for(auto x:stones)
            if(mp[x])
                ct++;
        return ct;
        
    }
};
