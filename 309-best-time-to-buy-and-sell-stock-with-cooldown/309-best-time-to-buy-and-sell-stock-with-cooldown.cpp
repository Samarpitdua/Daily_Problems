class Solution {
public:
    int maxProfit(vector<int>& p) {
        int temp = p[0];
        int n = p.size();
        int a[n] , b[n] , c[n];
        a[0] = -p[0] , b[0] = 0 , c[0] = 0;
        for(int i = 1 ; i < p.size() ; i++)
        {
            a[i] = max(a[i-1] , -p[i] + c[i - 1]);
            b[i] = max(b[i-1] , a[i - 1] + p[i]);
            c[i] = max(c[i-1] , b[i - 1]);
        }
        return b[n - 1];
    }
};