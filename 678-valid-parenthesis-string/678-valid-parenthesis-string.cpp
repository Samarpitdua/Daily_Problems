class Solution {
public:
    bool checkValidString(string s) {
        stack<char> st;
        int ct = 0 ,lb =0 , rb = 0;
        for(int i =0 ; i < s.size() ;i++){
            if(s[i] == '(')
                st.push(s[i]);
            else if(s[i] == ')')
            {
                if(st.empty())
                {
                    if(!lb)
                        return false;
                    else
                        lb--;
                }
                else if(st.top() == '(')
                    st.pop();
                else
                    st.pop() , rb += 2;
            }
            else{
                if(st.empty())
                {
                    lb ++;
                }
                else
                {
                    st.pop();
                    lb += 2;
                }
            }
        }
        // ct = 0;
        while(!st.empty()){
            if(st.top() == '(')
            {
                if(rb > 0)
                    rb-- , st.pop();
                else
                    return false;
            }
            else if(st.top() == '*')
            {
                rb++;
                st.pop();
            }
        }
        return true;
    }
};