class Solution {
public:
    int hammingDistance(int x, int y) {
        int ct = 0;
        int n= x ^ y;
        while(n)
        {
            if(n&1)
                ct++;
            n=n>>1;
        }
        return ct;
    }
};
