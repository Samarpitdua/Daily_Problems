class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long , long long> up;
        long long cnt = 0;
        for(int i = 0 ; i < n ; i++){
        cnt += up[i - nums[i]];
        up[i - nums[i]]++;
    }
    return 1ll * n * (n - 1) / 2 - cnt;
        
    }
};