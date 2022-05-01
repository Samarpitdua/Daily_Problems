class Solution {
public:
    string removeDigit(string number, char digit) {
        int poss = -1 , lastChoice = -1;
        for(int i = 0 ; i < number.size() ;i++)
        {
            if(number[i] == digit)
                poss = i;
            else
            {
                if(poss == -1)
                    continue;
                else if(i - 1 == poss)
                {
                    if(number[i] > number[poss])
                        break;
                    else
                    {
                        lastChoice = i - 1;
                        poss = -1;
                    }
                }
            }
        }
        if(poss != -1)
            number.erase(number.begin() + poss);
        else
            number.erase(number.begin() + lastChoice);
        return number;
    }
};