class Solution {
public:
    int countEven(int num) {
        int sum = 0;
        int num2 = num;
        while(num2)
        {
            int rem = num2 % 10;
            sum += rem;
            num2 /= 10;
        }
        if(sum & 1)
        {
            return ((num+1) / 2 - 1);
        }
        return (num / 2);
        
    }
};