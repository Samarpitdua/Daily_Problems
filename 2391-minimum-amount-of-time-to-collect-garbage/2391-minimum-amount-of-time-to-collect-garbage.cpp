class Solution {
public:
    int garbageCollection(vector<string>& g, vector<int>& travel) {
        int ans = 0 , ans1 =0 , ans2 = 0 , ans3 = 0;
        int p=0,g1=0,m=0;
        for(int i = 0;  i < g.size() ;i++)
        {
            for(auto x : g[i])
                {
                    if(x == 'G')
                        g1++;
                    if(x == 'P')
                        p++;
                    if(x == 'M')
                        m++;
                    
                }
        }
        for(int i = 0;  i < g.size() ;i++)
        {
            for(auto x : g[i])
                {
                    if(x == 'G')
                        ans1++;
                }
            if(i != 0)
            {
                ans += travel[i - 1];
            }
            
            if(ans1 == g1)
                    break;
        }
        // cout<<ans<<" ";
        for(int i = 0;  i < g.size() ;i++)
        {
            for(auto x : g[i])
                {
                    if(x == 'P')
                        ans2++;
                    
                }
            if(i != 0)
            {
                ans += travel[i - 1];
            }
            
            if(ans2 == p)
                break;
        }
        // cout<<ans<<" ";
        for(int i = 0;  i < g.size() ;i++)
        {
            for(auto x : g[i])
                {
                    if(x == 'M')
                        ans3++;
                    
                }
            if(i != 0)
            {
                ans += travel[i - 1];
            }
            
            if(ans3 == m)
                    break;
        }
        // cout<<ans<<" ";
        // cout<<p3<<" ";
        // cout<<ans1 <<" "<<ans2<<" "<<ans3<<endl;
        ans += (m + p + g1);
        return ans;
    }
};