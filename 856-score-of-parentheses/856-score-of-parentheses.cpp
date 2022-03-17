class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        int ct=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                st.push(-1);
            else if(st.top()==-1)
            {
                st.pop();
                st.push(1);
            }
            else 
            {
                int res=st.top();
                st.pop();
                if(st.top()==-1)
                {
                    st.pop();
                    st.push(2*res);
                }
                else
                {
                    while(!st.empty() and st.top()!=-1)
                    {
                        res+=st.top();
                        st.pop();
                    }
                    if(!st.empty())
                    {
                        st.pop();
                        res*=2;
                    }
                    st.push(res);
                }
            
            }
        }
        while(!st.empty())
        {
            ct+=st.top();
            st.pop();
        }
        return ct;
    }
};