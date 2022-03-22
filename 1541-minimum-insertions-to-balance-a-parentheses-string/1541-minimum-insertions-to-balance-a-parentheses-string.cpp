class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int ct = 0;
        for(int i = 0 ; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                if(st.empty() or st.top() == '2')
                {
                    st.push('2');
                }
                else if(st.top() == '1')
                {
                    st.pop();
                    ct++;
                    st.push('2');
                }       
            }
            else
            {
                if(st.empty())
                {
                    st.push('1');
                    ct++;
                }
                else if(st.top() == '2')
                {
                    st.pop();
                    st.push('1');
                }
                else if(st.top() == '1')
                    st.pop();
            }
        }
        
            if(st.empty())return ct;
        while(!st.empty()){
            if(st.top() == '2')
                ct += 2;
            else if(st.top() == '1')
                ct++;
            st.pop();
        }
        return ct;
    }
    
};