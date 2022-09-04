class Solution {
public:
    int countOdds(int low, int high) {
        int ans = 0;
        ans += (high - low) / 2;
        if(low&1 or high&1)
            ans++;
        return ans;
        
    }
};