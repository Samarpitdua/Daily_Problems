class Solution {
public:
    int countGoodSubstrings(string s) {
        if(s.size() < 3)
            return 0;
        
        int i = 0 , j = 1 , ans = 0;
        
        for(int k = 2 ; k < s.size() ; k++ )
        {
            if(s[k] != s[i] and s[i] != s[j] and s[k] != s[j])
                ans++;
            i = j , j = k;
        }
        return ans;
    }
};