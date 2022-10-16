class Solution {
public:
    int countTime(string time) {
        int ans = 1;
        if(time[0] == '?' and time[1] != '?')
        {
            if(time[1] > '3')
            {
                ans *= 2;
            }
            else
                ans *= 3;
        }
        if(time[1] == '?' and time[0] != '?')
        {
            if(time[0] == '0' or time[0] == '1')
            {
                ans *= 10;
            }
            else
                ans *= 4;
        }
        if(time[0] == '?' and time[1] == '?')
        {
            ans *= 24;
        }
        if(time[3] == '?')
        {
            ans *= 6;
        }
        if(time[4] == '?')
        {
            ans *= 10;
        }
        return ans;
    }
};