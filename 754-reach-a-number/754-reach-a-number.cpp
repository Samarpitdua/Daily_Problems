class Solution {
public:
    int reachNumber(int target) {
        int  ans = 0 , ct = 0;
        if(target < 0)
            target = -target;
        while(1){
            ct++;
            // temp += ct;
            ans += ct;
            if(ans == target)
                return ct;
            if(ans > target and (ans - target) % 2 == 0)
                return ct;   
        }
        return -1;
    }
};