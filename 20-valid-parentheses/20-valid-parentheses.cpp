class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        st.push(s[0]);
        for(int i=1;i<s.size();i++)
        {
            if(!st.empty() and s[i]==')' and st.top()=='(')
                st.pop();
            else if(!st.empty() and s[i]=='}' and st.top()=='{')
                st.pop();
            else if(!st.empty() and s[i]==']' and st.top()=='[')
                st.pop();
            else
                st.push(s[i]);
        }
        if(st.empty())return true;
        else return false;
        
    }
};