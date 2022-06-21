class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(num == 0)
            return 0;
        int rem = num % 10;
        for(int i = 1 ; i <= 10 ; i++)
        {
            if((k * i) % 10 == rem)
            {
                if(num < (k * i))
                    return -1;
                else
                    return i;
            }
        }
        return -1;
        
    }
};