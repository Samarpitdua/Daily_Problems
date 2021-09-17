class Solution {
public:
    string reversePrefix(string s, char ch) {
        int n=s.size();
        string t="";
        int p=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=ch and p==0)
                t+=s[i];
            else if(s[i]==ch and p==0)
            {
                p=1;
                t+=s[i];
                reverse(t.begin(),t.end());
                
            }
            else
                t+=s[i];
        }
        return t;
        
    }
};
