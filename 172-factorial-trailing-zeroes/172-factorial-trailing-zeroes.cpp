class Solution {
public:
    int trailingZeroes(int n) {
        long long ans = 0;
        for(long long int i = 5 ; int(n / i) > 0 ; i *= 5){
            ans += (n / i);
        }
        return ans;
    }
};