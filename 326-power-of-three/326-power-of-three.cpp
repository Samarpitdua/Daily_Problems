class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n>0)
        {
            if(n==1)
                return true;
            else
            {
                if(n%3==0)
                    n/=3;
                else
                    return false;
            }
        }
        return false;
    }
};