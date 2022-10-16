class Solution {
public:
    int countLetters(string s) {
        set<char> st;
        int ans = 0 , ct = 0;
        for(auto x : s)
        {
            st.insert(x);
            if(st.size() == 1)
            {
                ct++;
                continue;
            }
            else
            {
                ans += (ct * (ct + 1)) / 2;
                ct = 1;
                st.clear();
                st.insert(x);
            }
        }
        ans += (ct * (ct + 1)) / 2;
        return ans;
    }
};