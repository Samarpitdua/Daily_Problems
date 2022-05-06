class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char , int>> st;
        int p = 1;
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(st.empty())
            {
                st.push({s[i] , p});
            }
            else if(st.top().first == s[i])
            {
                int temp = st.top().second + 1;
                if(temp == k)
                {
                    while(temp > 1)
                    {
                        temp--;
                        st.pop();
                    }
                }
                else
                    st.push({s[i] , temp});
            }
            else
            {
                st.push({s[i] , p});
            }
        }
        string ans = "";
        while(!st.empty())
        {
            ans.push_back(st.top().first);
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};