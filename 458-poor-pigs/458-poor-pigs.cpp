class Solution {
public:
    int poorPigs(int buckets, int d, int t) {
        int temp = t / d;
        int pigs = 0;
        while (pow(temp + 1 , pigs) < buckets)
            pigs++;
        return pigs  ; 
    }
};