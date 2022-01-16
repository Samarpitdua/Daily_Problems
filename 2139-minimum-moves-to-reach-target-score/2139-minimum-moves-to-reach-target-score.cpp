class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ct = 0;
        while(target != 1)
        {
            if(target & 1)
                ct++ , target--;
            else if(maxDoubles)
            {
                ct++;
                target /= 2;
                maxDoubles--;
            }
            else
            {
                ct += (target - 1);
                break;
            }
        }
        return ct;
        
    }
};