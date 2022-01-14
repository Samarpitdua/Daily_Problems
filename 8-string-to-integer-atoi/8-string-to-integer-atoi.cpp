class Solution {
public:
    int myAtoi(string s) {
        int toggle = 0 , ans = 0 , p = -1 , q = -1;
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(p == -1 and s[i] == ' ')     //check for starting spaces
                continue;
            else
            {
                if(p == -1)     //checking if number is positive or negative
                {
                    if(s[i] == '-')
                        toggle = 1;
                    p = 1;
                    if(s[i] == '+' or s[i] == '-')
                        continue;
                }
            
                if(s[i] == ' ')
                    break;
                else if(q == -1 and s[i]=='0')  //check for leading zeroes
                    continue;
                else
                {
                    q = 1;
                    if(s[i] >= '0' and s[i] <= '9')
                    {
                        if(ans > (INT_MAX)/10 ||((ans == INT_MAX/10) && (s[i] - '0') > INT_MAX%10))
                        {
                            if(toggle)return INT_MIN;
                            return INT_MAX;
                        }
                            ans = ans * 10 + (s[i] - '0');
                    }
                    else
                        break;
                }
            }
        }
        if(toggle)
            ans *= -1;
        return ans;
    }
};