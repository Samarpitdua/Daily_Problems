class Solution {
public:
    string removeKdigits(string s, int k) {
       stack<char> st;
        string ans = "";
        st.push(s[0]);
        for(int i = 1 ; i < s.size();i++)
        {
            if(k <= 0)
            {
                st.push(s[i]);
                continue;
            }
            if(s[i] > st.top())
            {
                st.push(s[i]);
                continue;
            }
            else if(s[i] == st.top())
                st.push(s[i]);
            else
            {
                while(k and !st.empty() and s[i] < st.top())
                {k--;
                st.pop();}
                st.push(s[i]);
            }
        }
        while(!st.empty() and k>0)
        {
            if(st.size() > 1)
            {
                k--;
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if(a > b)
                    st.push(b);
                else st.push(a);
                continue;
            }    
                
            k--;
            st.pop();
        }
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        string temp = "";
       // cout<<ans<<" ";
        int p = -1;
        for(auto x : ans)
        {
            if(x=='0' and p == -1)
                continue;
            else
            {
                p = 1;
                temp += x;
            }
        }
        if(p == -1)
            return "0";
        return temp;
    }
};