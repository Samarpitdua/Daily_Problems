class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> freq(n , vector<int>(26 , 0));
        for(int i = 0 ; i < words.size() ;i++)
        {
            for(auto x : words[i])
            {
                freq[i][x - 'a']++;
            }
        }
        stack<int> st;
        for(int i = 0 ; i < n ;i++)
        {
            if(st.empty())
            {
                st.push(i);
            }
            else
            {
                if(freq[st.top()] != freq[i])
                    // st.pop();
                st.push(i);
            }
        }
        vector<string> ans;
        while(!st.empty())
        {
            ans.push_back(words[st.top()]);
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};