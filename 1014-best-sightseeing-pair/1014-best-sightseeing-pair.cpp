class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0 , sum = 0;
        for(auto x : values)
        {
            ans = max(ans , sum + x);
            sum = max(sum , x) - 1;
        }
        return ans;
    }
};