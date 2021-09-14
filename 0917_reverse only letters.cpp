class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n=s.size();
        for(int i=0,j=n-1;i<=j;)
        {
            if((s[i]>='a' and s[i]<='z') or (s[i]>='A' and s[i]<='Z' ))
            {
                if((s[j]>='a' and s[j]<='z') or (s[j]>='A' and s[j]<='Z'))
                {
                  swap(s[i],s[j]);
                  i++,j--;
                }
                else
                    j--;
            }
            else 
                i++;
        }
        return s;
        
    }
};
