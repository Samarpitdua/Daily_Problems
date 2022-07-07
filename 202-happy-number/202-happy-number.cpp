class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int , int> mp;
        while(n != 1){
            if(mp.find(n) != mp.end())
                return false;
             mp[n]++;
            int temp = 0;
            while(n){
                int r = n % 10;
                n /= 10;
                temp += r * r;
            }
            n = temp;
           
        }
        return true;
        
    }
};