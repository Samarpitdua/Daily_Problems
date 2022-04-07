class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        for(int i = 0 ; i < n ;i++)
        {
            if(st.empty())
            {
                if(s[i] =='}' or s[i] == ']' or s[i] == ')')
                    return false;
                else
                    st.push(s[i]);
            }
            else
            {
                if(s[i] == '{' or s[i] == '[' or s[i] == '(')
                    st.push(s[i]);
                else if(s[i] == '}')
                {
                    if(st.top() == '{')
                        st.pop();
                    else
                        return false;
                }
                else if(s[i] == ')')
                {
                    if(st.top() == '(')
                        st.pop();
                    else
                        return false;
                }
                else if(s[i] == ']')
                {
                    if(st.top() == '[')
                        st.pop();
                    else
                        return false;
                }
            }
        }
        return st.empty();
    
        
    }
};