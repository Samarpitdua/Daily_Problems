class Solution {
public:
    int minimumSum(int num) {
        int a[4];
         a[0] = num % 10;
        num /= 10;
         a[1] = num % 10;
        num/= 10;
         a[2] = num % 10;
        num /= 10;
         a[3] = num % 10;
        num/= 10;
        sort(a,a+4);
        int ans1 = a[0]*10 + a[3];
        int ans2 = a[1]*10 + a[2];
        return (ans1 + ans2);
    }
};