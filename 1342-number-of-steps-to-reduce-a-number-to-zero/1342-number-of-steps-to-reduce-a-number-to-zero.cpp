class Solution {
public:
    int numberOfSteps(int num) {
        int ct = 0;
        while(num > 0)
        {
            if(num & 1)
                num--;
            else
                num /= 2;
            ct++;
        }
        return ct;
            
        
    }
};