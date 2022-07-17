class Solution {
public:
    int get(int x){
        int ct = 0;
        while(x){
            int r = x % 10;
            x /= 10;
            ct += r;
        }
        return ct;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int , int> mp;
        int ans = -1;
        for(auto x : nums){
            int sum = get(x);
            if(mp.find(sum) != mp.end()){
                ans = max(ans , mp[sum] + x);
                mp[sum] = max(mp[sum] , x);
            }
            else
                mp[sum] = x;
        }
        return ans;
        
    }
};