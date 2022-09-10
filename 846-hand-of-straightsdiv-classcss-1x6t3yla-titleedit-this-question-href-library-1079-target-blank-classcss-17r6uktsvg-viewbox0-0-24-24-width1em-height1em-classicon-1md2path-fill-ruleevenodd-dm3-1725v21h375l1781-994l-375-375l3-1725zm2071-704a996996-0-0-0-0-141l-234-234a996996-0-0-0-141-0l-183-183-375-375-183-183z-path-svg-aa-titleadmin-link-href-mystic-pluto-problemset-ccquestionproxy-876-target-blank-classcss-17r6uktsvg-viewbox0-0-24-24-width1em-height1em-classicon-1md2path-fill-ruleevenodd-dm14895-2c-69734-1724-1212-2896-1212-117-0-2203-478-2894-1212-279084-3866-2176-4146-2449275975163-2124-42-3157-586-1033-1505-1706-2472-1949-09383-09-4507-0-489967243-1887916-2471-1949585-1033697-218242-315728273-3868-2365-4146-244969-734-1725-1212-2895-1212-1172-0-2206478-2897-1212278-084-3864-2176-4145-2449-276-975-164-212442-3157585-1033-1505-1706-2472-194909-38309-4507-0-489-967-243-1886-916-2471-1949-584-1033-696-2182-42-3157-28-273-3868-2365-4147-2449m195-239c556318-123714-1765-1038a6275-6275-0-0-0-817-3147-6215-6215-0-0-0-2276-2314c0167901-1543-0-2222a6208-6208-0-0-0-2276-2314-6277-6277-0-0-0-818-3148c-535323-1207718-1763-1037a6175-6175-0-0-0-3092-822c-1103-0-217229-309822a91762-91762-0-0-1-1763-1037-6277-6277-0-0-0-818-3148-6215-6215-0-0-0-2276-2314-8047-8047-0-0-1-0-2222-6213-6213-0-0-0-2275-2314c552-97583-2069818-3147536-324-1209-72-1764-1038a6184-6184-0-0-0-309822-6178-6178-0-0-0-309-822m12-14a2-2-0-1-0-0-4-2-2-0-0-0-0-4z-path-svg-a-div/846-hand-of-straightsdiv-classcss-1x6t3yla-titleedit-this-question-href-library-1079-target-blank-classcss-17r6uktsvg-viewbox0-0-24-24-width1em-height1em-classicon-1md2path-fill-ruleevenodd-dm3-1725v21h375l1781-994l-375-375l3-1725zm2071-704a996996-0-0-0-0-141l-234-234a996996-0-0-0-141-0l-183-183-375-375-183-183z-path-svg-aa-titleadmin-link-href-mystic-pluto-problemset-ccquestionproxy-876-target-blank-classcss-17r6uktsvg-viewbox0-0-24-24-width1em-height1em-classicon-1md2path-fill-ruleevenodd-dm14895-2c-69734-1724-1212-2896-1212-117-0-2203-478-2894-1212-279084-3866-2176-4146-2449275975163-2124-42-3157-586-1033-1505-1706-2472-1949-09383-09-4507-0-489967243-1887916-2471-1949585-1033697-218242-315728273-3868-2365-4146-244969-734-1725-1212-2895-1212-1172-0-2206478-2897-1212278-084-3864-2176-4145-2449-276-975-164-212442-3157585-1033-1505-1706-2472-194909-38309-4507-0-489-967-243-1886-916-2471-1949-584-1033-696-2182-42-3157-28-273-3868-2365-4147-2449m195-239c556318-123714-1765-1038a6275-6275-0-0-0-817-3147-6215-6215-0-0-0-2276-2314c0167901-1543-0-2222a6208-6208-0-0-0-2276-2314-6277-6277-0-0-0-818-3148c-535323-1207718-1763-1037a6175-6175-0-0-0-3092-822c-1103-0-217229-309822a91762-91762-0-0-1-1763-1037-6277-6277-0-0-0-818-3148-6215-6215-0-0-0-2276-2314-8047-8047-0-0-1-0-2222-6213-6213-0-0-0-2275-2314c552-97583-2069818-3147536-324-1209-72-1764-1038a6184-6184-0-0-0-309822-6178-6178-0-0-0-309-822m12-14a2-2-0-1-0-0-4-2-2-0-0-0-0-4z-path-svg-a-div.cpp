class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int g) {
        int n = hand.size();
        if(n % g != 0)
           return false;
        map<int , int> mp;
        for(auto x : hand)
            mp[x]++;
        if(g == 1)
            return true;
        
            int ct = 0;
        while(mp.size())
        {
            int p = -1;
            int temp = -1;
            for(auto& x : mp)
            {
                
                    if(x.second == 0)
                    {
                        mp.erase(x.first);
                        continue;
                    }
                // cout<<x.first<<" "<<x.second<<" "<<ct<<endl;
                if(p == -1)
                {
                    p = 1;
                    ct = 1;
                    temp = x.first;
                    x.second--;
                }
                else
                {
                    if(x.first == (temp + 1))
                    {
                        x.second--;
                        temp = x.first;
                        ct++;
                        if(ct == g)
                        {
                            p = -1;
                            ct = 0;
                            break;
                        }
                    }
                    else
                    {
                        return false;
                    }
                }
                
            }
        }
        if(ct == 0)
        return true;
        return false;
    }
};