class Solution {
public:
    bool solve(int start , int end , string s)
    {
        while(start < end)
        {
            if(s[start] != s[end])
                return false;
            start++ , end--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.size();
        int i = 0 , j = n - 1 , ct = 0;
        while(i < j)
        {
            if(s[i] == s[j])
            {
                i++ , j--;   
                continue;
            }
                if(solve(i + 1, j , s) or solve(i , j - 1 , s))
                    return true;
                return false;
                
        }
        return true;
    }
};