class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        vector<int> ans;
        stack<int> st;
        for(int i = 0 ; i <= n ;i++){
            st.push(i);
            if(i == n or s[i] == 'I'){
                while(!st.empty()){
                    ans.push_back(st.top());
                    st.pop();
                }
            }
        }
        return ans;
    }
};