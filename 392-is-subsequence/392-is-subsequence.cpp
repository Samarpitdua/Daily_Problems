class Solution {
public:
    bool isSubsequence(string s, string t) {
        int k = 0;
        if(s == "")
            return true;
        
        for(int i = 0 ; i < t.size() ; i++)
        {
            if(s[k] == t[i])
                k++;
            if(k == s.size())
                return true;
        }
        return false;
    }
};