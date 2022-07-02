class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int change = 0 , ten = 0;
        for(auto x : bills)
        {
            if(x == 5)
                change++;
            else
            {
                if(x == 10)
                {
                    if(change)
                        change-- , ten++;
                    else
                        return false;
                }
                else
                {
                    if(ten and change)
                        ten-- , change--;
                    else if(change >= 3)
                        change -= 3;
                    else
                        return false;
                }
            }
        }
        return true;
    }
};