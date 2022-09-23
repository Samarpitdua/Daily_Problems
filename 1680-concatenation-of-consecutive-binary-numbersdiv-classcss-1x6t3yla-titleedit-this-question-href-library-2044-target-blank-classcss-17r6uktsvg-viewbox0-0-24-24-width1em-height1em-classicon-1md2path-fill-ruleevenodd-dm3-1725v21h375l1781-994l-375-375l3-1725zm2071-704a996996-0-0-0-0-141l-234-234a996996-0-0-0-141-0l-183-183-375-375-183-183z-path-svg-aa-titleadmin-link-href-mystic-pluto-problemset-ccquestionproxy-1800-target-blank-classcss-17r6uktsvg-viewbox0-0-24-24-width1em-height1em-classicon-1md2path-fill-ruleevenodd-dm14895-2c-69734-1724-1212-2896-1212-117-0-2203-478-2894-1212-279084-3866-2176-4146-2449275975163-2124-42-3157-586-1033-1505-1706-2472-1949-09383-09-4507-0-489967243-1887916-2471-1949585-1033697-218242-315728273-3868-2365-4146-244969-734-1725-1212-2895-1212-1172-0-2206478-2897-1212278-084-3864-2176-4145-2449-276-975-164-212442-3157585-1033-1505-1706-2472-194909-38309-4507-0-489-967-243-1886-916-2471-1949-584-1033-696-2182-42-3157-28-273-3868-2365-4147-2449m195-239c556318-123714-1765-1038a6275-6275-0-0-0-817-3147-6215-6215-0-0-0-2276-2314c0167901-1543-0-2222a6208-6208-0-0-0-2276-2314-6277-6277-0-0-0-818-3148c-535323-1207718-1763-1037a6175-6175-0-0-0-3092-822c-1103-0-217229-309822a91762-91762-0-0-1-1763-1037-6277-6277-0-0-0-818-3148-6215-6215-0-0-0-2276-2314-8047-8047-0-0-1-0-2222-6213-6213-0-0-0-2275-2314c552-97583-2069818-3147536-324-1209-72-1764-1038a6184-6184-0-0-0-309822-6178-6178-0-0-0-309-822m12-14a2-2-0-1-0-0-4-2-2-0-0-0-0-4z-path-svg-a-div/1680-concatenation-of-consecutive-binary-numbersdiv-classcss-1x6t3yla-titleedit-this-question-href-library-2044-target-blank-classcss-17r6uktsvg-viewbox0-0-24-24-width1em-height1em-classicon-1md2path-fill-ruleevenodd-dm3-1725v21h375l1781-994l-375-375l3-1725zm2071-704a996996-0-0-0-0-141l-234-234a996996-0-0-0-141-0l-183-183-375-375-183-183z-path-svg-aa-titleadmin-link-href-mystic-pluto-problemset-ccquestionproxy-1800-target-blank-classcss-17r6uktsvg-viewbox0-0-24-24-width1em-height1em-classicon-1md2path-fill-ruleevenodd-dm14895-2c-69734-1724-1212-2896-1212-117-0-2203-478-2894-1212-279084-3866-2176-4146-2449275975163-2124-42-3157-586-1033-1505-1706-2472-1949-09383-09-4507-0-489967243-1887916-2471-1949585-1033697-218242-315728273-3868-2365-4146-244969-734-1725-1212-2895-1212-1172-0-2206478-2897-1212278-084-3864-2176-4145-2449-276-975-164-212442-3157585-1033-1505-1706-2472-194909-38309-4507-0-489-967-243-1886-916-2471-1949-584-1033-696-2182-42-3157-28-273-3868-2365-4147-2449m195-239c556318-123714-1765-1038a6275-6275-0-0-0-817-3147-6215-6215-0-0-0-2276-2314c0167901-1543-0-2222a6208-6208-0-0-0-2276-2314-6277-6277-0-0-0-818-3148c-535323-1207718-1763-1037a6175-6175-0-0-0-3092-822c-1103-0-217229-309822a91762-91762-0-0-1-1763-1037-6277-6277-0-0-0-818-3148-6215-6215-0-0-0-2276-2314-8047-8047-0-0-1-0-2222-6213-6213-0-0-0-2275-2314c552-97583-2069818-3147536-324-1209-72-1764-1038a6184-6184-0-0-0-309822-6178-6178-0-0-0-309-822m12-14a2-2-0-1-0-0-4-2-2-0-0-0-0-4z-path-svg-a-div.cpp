class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans = 0, mod = 1000000007, curr_len = 0;
        for (int i = 1; i <= n; i++) {
	
            if ((i & (i-1)) == 0)
                curr_len++;
				
            ans = (ans << curr_len) % mod;
            ans += i % mod;
        }
        return ans;
    }
};