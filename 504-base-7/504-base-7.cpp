class Solution {
public:
    string convertToBase7(int num) {
        string ans = "";
        int sign = 0;
        if(!num)
            return "0";
        if(num < 0)
            sign++;
        num = abs(num);
        while(num)
        {
            ans = to_string(num % 7) + ans ;
            num /= 7;
        }
        if(sign)
        {
            ans = "-" + ans;
        }
        return ans;
    }
};