class Solution {
public:
    long long smallestNumber(long long num) {
        int p = 0;
        if(num < 0)
        {
            num *= -1;
            p = 1;
        }
        string s = to_string(num);
        
        sort(s.begin() , s.end());
        if(p)
            reverse(s.begin() , s.end());
        string ans = "";
        // cout<<s<<" ";
        int z = 0 , l = -1;
        for(auto x : s)
        {
            if(x == '0' and l == -1)
                z++;
            else
            {
                if(l == -1)
                {
                    l = 1;
                    ans += x;
                    while(z>0)
                        z-- , ans += '0';
                }
                else
                    ans += x;
            }
        }
        while(z>0)
            z-- , ans += '0';
        long long temp = stoll(ans);
        if(p)
            temp *= -1;
        return temp;
            
    }
};