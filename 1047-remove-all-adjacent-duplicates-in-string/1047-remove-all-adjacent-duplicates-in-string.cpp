class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(st.empty())
                st.push(s[i]);
            else if(st.top()!=s[i])
                st.push(s[i]);
            else
                st.pop();
        }
        string t="";
        while(!st.empty())
        {
            t.push_back(st.top());
            st.pop();
        }
        reverse(t.begin(),t.end());
        return t;
    }
};