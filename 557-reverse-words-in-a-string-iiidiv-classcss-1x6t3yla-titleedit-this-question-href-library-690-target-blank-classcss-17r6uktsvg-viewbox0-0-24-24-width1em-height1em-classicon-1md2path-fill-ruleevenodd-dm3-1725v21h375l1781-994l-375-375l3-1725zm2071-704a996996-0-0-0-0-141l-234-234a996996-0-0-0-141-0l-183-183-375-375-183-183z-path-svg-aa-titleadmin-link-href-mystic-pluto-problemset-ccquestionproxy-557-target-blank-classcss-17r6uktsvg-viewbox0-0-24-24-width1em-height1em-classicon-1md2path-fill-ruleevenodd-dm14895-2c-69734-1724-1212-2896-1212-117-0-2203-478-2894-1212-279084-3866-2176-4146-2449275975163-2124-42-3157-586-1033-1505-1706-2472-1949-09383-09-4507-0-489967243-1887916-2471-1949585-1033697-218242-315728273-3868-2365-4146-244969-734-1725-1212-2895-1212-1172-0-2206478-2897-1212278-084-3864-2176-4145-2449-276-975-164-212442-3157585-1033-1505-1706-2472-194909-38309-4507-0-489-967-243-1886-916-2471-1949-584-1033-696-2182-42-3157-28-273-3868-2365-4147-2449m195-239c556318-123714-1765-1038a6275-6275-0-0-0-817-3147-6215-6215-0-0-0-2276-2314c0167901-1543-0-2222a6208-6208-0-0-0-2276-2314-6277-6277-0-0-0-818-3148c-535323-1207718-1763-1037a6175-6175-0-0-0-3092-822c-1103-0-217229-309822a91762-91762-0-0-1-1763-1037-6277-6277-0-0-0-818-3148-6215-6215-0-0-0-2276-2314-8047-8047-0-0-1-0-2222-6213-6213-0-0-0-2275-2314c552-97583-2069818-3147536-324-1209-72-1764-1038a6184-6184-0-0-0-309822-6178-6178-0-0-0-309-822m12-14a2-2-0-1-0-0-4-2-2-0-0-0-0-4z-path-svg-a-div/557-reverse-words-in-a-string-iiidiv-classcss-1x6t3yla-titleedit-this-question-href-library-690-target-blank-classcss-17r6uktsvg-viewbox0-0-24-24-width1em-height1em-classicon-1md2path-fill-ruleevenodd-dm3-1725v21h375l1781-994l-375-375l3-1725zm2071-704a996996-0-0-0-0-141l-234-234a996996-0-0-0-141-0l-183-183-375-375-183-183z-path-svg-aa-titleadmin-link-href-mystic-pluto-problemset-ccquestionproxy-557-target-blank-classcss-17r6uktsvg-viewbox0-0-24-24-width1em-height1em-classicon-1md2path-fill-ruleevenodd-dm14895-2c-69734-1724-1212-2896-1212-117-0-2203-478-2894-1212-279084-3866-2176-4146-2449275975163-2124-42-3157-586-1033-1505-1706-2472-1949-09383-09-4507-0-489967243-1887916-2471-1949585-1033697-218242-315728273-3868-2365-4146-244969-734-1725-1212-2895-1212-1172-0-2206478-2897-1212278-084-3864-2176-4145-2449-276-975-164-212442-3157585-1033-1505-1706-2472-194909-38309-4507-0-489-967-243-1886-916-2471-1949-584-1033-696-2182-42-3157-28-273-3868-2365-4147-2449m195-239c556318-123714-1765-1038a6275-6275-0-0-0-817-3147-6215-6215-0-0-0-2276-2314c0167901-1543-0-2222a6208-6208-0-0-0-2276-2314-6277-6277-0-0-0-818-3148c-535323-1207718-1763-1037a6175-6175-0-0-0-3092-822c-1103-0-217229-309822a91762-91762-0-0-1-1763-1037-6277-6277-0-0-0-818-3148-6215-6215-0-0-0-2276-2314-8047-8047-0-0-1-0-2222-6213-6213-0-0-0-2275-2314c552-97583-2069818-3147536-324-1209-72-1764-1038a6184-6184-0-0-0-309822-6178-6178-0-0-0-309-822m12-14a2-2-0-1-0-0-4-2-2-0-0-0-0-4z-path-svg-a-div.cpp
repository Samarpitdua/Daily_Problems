class Solution {
public:
    string reverseWords(string s) {
        string t="",u="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                reverse(t.begin(),t.end());
                u+=t;
                u+=" ";
                t="";
            }
            else
                t+=s[i];
        }
         reverse(t.begin(),t.end());
                u+=t;
        return u;
        
    }
};