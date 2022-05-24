class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length() , ans = 0;
        stack<int> st;
        for (int i = 0; i < n; i++) 
        {
            if (s[i] == '(')
                st.push(i);
            else 
            {
                if (!st.empty())
                {
                    if (s[st.top()] == '(')
                        st.pop();
                    else
                        st.push(i);
                }
                else
                    st.push(i);
            }
        }
        if (st.empty())
            ans = n;
        else 
        {
            int a = n, b = 0;
            while (!st.empty())
            {
                b = st.top();
                st.pop();
                ans = max(ans , a - b - 1);
                a = b;
            }
            ans = max(ans, a);
        }
        return ans;
    }
};