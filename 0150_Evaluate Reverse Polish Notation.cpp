class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto x:tokens)
        {
            if(x == "+" or x == "-" or x == "*" or x == "/" or x == "^")
            {
                int temp1 = st.top();
                st.pop();
                int temp2 = st.top();
                st.pop();
                if(x == "+")
                    temp2 += temp1;
                else if(x == "-")
                    temp2 -= temp1;
                else if(x == "*")
                    temp2 *= temp1;
                else if(x == "/")
                    temp2 /= temp1;
                else
                    temp2 ^= temp1;
                st.push(temp2);
            }
            else
            {
                st.push(stoi(x));
            }
        }
        return st.top();
    }
};
