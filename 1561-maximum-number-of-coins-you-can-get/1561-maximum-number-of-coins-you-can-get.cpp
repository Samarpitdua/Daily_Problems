class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size() , ans = 0;
        for(int i = 0 ,j = n - 1 ; i < j ; i++ , j -= 2)
        {
            ans += piles[j - 1];
        }
        return ans;
    }
};