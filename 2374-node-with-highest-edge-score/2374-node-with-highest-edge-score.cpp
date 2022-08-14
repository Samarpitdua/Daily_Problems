class Solution {
public:
    int edgeScore(vector<int>& edges) {
        long long int ct = 0;
        map<long long int ,long long int> mp;
        for(auto x : edges){
            mp[x] += ct;
            ct++;
        }
        
        long long int ans = 0 , maxi = 0;
        for(auto x : mp){
            if(x.second > maxi){
                maxi = x.second;
                ans = x.first;
            }
        }
        return ans;
    }
};