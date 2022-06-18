class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double ans = 0.0;
        int sum = 0;
        int tmp = 0;
        int h = 0;
        for(auto x : brackets)
        {
            int temp;
            if(x[0] < income)
            {
                temp = x[0] - h;
                ans += ((temp * x[1]) /(double) 100);
            }
            else
            {
                temp = income - h;
                ans += ((temp * x[1]) /(double) 100);
                break;
            }
            h = x[0];
        }
        return ans;
    }
};