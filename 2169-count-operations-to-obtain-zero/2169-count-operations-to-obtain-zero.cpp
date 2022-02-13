class Solution {
public:
    int countOperations(int num1, int num2) {
        int ct = 0;
        while(1)
        {
            if(num1 == 0 or num2 == 0)
                return ct;
            if(num2 > num1)
            {
                num2 -= num1;
            }
            else
                num1 -= num2;
            ct++;
        }
            
    }
};