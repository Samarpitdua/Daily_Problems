class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        int n = s.size();
        stack<char>st;
        
        int i;
        for( i = 0;i < n; i++)
        {
            if(st.empty())
                st.push(s[i]);
            else
            {
                if(abs(st.top() - s[i]) == 32)
                {
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                }
            }
        }
        while(!st.empty())
        {
            char ch = st.top();
            ans += ch;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
