class Solution {
public:
    int countCollisions(string direct) {
        int n = direct.size();
        int p = 0 , ans = 0 , start = n , end = -1;
        int r = 0 , s = 0 , l =0;
        
        for(int i = n - 1 ; i >= 0 ;i--)
        {
            if(direct[i] != 'R')
            {
                end = i;
                break;
            }
        }
        
        for(int i = 0 ; i < n ; i++)
        {
            if(direct[i] != 'L')
            {
                start = i;
                break;
            }
        }
        
        for(int i = start ; i <= end ; i++)
        {
            if(direct[i] == 'R')
            {
                l = 0;
                r++;
                s = 0;
            }
            else if(direct[i] == 'S')
            {
                l =0;
                ans += r;
                s = 1;
                r = 0;
            }
            else
            {
                if(l > 0)
                {
                    ans++;
                    continue;
                }
                if(r > 0)
                {
                    r--;
                    ans += (2);
                    ans += r;
                }
                ans += s;
                r = 0;
                s = 0;
                l = 1;
            }
        }
            
        return ans;
    }
};