class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>st;
        for(auto x:ops)
        {
            if(x == "C")
                st.pop();
            else if(x == "D")
            {
                int temp = st.top();
                st.push(temp*2);
            }
            else if(x == "+")
            {
                int temp1 = st.top();
                st.pop();
                int temp2 = st.top();
                st.pop();
                st.push(temp2);
                st.push(temp1);
                st.push(temp1 + temp2);
            }
            else
            {
                st.push(stoi(x));
            }
          //  cout<<st.top()<<" ";
        }
        int ans = 0;
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};
