class Solution {
public:
    bool isArmstrong(int n) {
        int m = n , ct = 0;
        while(m){
            ct++;
            m /= 10;
        }
        long long sum = 0;
        m = n;
        while(n)
        {
            int r = n % 10;
            sum += pow(r , ct);
            n /= 10;
        }
        return sum == m;
        
        
    }
};