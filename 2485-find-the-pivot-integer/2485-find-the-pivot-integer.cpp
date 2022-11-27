class Solution {
public:
    int pivotInteger(int n) {
        int i = 1 ,j = n , sum1 = 0, sum2 = 0;
        while(i < j)
        {
            if(sum1 == sum2)
            {
                sum1 += i;
                sum2 += j;
                i++ , j--;
            }
            else if(sum1 < sum2)
            {
                sum1 += i;
                i++;
            }
            else
            {
                sum2 += j;
                j--;
            }
        }
        if(sum1 == sum2)
            return i;
        else
            return -1;
        
    }
};