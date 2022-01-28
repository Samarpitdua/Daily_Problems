class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        unordered_map<int , int > mp;
        
        for(int i = 0 ; i < s.size() ;i++)
        {
            if(s[i] >= 'a' and s[i] <= 'z')
                continue;
            else
            {
                if(st.empty())
                {
                    if(s[i] == ')')
                    {
                        mp[i + 1] = 1;
                        continue;
                    }
                    else
                        st.push(i);
                }
                else
                {
                    if(s[i] == '(')
                        st.push(i);
                    else
                        st.pop();
                }
            }
        }
        while(!st.empty())
        {
            mp[st.top() + 1] = 1;
            st.pop();
        }
        string ans = "";
        for(int i = 0 ; i < s.size() ;i++)
        {
            if(!mp[i + 1])
                ans += s[i];
        }
        return ans;

    }
};