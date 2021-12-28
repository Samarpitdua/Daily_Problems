class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i = 0 ; i <= sqrt(c) ; i++)
        {
            double temp = sqrt( c - i * i );
            if(int(temp) == temp )
                return true;
        }
        return false;
        
    }
};