class Solution {
public:
    int minSwaps(string expr) {
          stack<char> st;
          int ct = 0;
          for(int i = 0 ; i < expr.size() ; i++)
          {
            if(st.empty() and expr[i] =='[')
                st.push(expr[i]);
              
            else if(st.empty() and expr[i] == ']')
                st.push('[') , ct++;
              
            else if(expr[i] == ']' and st.top() == '[')
                st.pop();
              
            else
                st.push(expr[i]);
          }
          int r = 0;
          while(!st.empty())
            r++ , st.pop();
        
            ct += r / 2;
            return ct / 2;
    }
};