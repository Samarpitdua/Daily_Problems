class Solution {
public:
    # define MOD 1000000
    int rabinKarp(string s , string t)
    {
        int m = t.size();
        int power = 1;
        for(int i = 0 ; i < m ;i++)
        {
            power *= 31;
            power %= MOD;
        }
        int patt_hash = 0;
        for(int i = 0 ; i < m ; i++)
        {
            patt_hash = (patt_hash * 31 + t[i]) % MOD;
        }
        int st_hash = 0;
        for(int i = 0 ; i < s.size() ;i++){
            st_hash = (st_hash * 31 + s[i]) % MOD;
            if(i < m - 1)
                continue;
            if(i >= m)
            {
                st_hash = (st_hash - s[i - m] * power) % MOD;
            }
            if(st_hash < 0)
                st_hash += MOD;
            
            if(st_hash == patt_hash)
            {
                if(s.substr(i - m + 1 , m) == t)
                    return i - m + 1;
                
            }
        }
        return -1;
    }
    int strStr(string haystack, string needle) {
        return rabinKarp(haystack , needle);   
    }
};