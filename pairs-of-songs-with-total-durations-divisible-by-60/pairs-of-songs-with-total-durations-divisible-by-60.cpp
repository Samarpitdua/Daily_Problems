class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ct = 0;
        map<int , int>mp;
        for(int i = 0 ; i < time.size() ; i++)
        {
            mp[time[i] % 60]++;
        }
        for(int i = 0 ; i < time.size() ; i++)
        {
            mp[time[i] % 60]--;
            int temp = 60 - (time[i] % 60);
            if(temp == 60)
                temp = 0;
            ct += mp[temp];
        }
        return ct;
        
    }
};