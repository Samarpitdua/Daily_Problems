#define mod 1000000007
class Solution {
public:
    int maxArea(int h, int w, vector<int>& ht, vector<int>& wt) {
        sort(ht.begin() , ht.end());
        sort(wt.begin() , wt.end());
        long long int maxiw = 0;
        long long int maxih = 0;
        ht.push_back(h);
        wt.push_back(w);
        for(int i = 0 ; i < ht.size() ;i++)
        {
            if(i == 0)
                maxih = max(maxih , (long long )ht[i]);
            else
                maxih = max(maxih , (long long )(ht[i] - ht[i - 1]));
        }
        
        for(int i = 0 ; i < wt.size() ;i++)
        {
            if(i == 0)
                maxiw = max(maxiw , (long long )wt[i]);
            else
                maxiw = max(maxiw , (long long) (wt[i] - wt[i - 1]));
        }
        long long ans =  ((maxih % mod) * (maxiw % mod) ) % mod;
        return ans;
    }
};