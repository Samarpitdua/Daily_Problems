class Solution {
public:
    int largestCombination(vector<int>& c) {
        int ct = 0 , ans = 0;
        for(int i = 0 ; i < 32 ;i++)
        {
            ct = 0;
            for(int j = 0 ; j < c.size() ;j++)
            {
                if((c[j] >> i) & 1 == 1)
                    ct++;
            }
            ans = max(ct , ans);
        }
        return ans;
    }
};