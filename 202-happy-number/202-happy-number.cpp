class Solution {
public:
    bool isHappy(int n) {
        map<int , int>mp;
        while(n != 1)
        {
            if(mp.find(n) != mp.end())
                return false;
            mp[n]++;
            int temp = n;
            vector<int> v;
            n = 0;
            while(temp > 0)
            {
                int r = temp % 10;
                temp /= 10;
                n += (r * r);
                v.push_back(r);
            }
        }
        return true;
        
    }
};