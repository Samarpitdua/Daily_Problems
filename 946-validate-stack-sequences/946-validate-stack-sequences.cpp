class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = pushed.size();
        int j = 0;
        for(int i = 0 ; i < n ;)
        {
            
            if(!st.empty() and popped[j] == st.top())
            {
                st.pop();
                j++;
            }
            else
            {
                st.push(pushed[i]);
                i++;
            }
        }
        while(!st.empty() and popped[j] == st.top())
        {
            st.pop();
            j++;
        }
        return (j == n);
            
    }
};