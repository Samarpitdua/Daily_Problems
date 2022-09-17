class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int>x;
        int ct=0;
        int count=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
                x.push(s[i]);
            else if((s[i]==')'||s[i]=='}'||s[i]==']')&&x.empty())
            {
                ct++;
                continue;
            }
            else
            {
                if(s[i]==')'&&x.top()=='(')
                {
                    x.pop();
                    continue;
                }
                else if(s[i]=='}'&&x.top()=='{')
                {
                    x.pop();
                    continue;
                }
                else if(s[i]==']'&&x.top()=='[')
                {
                    x.pop();
                    continue;
                }
                else
                {
                    ct++;
                    x.pop();
                }
            }
           
        }
         while(!x.empty())
            {
                x.pop();
                ct++;
            }
        return ct;
    }
};