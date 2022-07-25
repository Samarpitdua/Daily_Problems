class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int n = s.size();
        char sign = '+';
        long long int ans = 0, temp = 0;
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i]))
                temp = 10 * temp + s[i] - '0';
            
            if (!isdigit(s[i]) && !isspace(s[i]) || i == n - 1) {
                if (sign == '-')
                    st.push(-temp);
                
                else if (sign == '+')
                    st.push(temp);
                
                else 
                {
                    int num;
                    if (sign == '*' )
                        num = st.top() * temp;
                    else
                        num = st.top() / temp;
                    st.pop();
                    st.push(num);
                } 
                sign = s[i];
                temp = 0;
            }
        }
        while (!st.empty()) 
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};