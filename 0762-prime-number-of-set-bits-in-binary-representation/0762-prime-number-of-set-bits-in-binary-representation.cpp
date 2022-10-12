class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        set<int> st = {2, 3, 5, 7, 11, 13, 17, 19 };
        int cnt = 0;
        for (int i = left; i <= right; i++) {
            int bits = __builtin_popcount(i);
            cnt += st.find(bits) != st.end() ? 1 : 0;
        }
        return cnt; 
    }
};