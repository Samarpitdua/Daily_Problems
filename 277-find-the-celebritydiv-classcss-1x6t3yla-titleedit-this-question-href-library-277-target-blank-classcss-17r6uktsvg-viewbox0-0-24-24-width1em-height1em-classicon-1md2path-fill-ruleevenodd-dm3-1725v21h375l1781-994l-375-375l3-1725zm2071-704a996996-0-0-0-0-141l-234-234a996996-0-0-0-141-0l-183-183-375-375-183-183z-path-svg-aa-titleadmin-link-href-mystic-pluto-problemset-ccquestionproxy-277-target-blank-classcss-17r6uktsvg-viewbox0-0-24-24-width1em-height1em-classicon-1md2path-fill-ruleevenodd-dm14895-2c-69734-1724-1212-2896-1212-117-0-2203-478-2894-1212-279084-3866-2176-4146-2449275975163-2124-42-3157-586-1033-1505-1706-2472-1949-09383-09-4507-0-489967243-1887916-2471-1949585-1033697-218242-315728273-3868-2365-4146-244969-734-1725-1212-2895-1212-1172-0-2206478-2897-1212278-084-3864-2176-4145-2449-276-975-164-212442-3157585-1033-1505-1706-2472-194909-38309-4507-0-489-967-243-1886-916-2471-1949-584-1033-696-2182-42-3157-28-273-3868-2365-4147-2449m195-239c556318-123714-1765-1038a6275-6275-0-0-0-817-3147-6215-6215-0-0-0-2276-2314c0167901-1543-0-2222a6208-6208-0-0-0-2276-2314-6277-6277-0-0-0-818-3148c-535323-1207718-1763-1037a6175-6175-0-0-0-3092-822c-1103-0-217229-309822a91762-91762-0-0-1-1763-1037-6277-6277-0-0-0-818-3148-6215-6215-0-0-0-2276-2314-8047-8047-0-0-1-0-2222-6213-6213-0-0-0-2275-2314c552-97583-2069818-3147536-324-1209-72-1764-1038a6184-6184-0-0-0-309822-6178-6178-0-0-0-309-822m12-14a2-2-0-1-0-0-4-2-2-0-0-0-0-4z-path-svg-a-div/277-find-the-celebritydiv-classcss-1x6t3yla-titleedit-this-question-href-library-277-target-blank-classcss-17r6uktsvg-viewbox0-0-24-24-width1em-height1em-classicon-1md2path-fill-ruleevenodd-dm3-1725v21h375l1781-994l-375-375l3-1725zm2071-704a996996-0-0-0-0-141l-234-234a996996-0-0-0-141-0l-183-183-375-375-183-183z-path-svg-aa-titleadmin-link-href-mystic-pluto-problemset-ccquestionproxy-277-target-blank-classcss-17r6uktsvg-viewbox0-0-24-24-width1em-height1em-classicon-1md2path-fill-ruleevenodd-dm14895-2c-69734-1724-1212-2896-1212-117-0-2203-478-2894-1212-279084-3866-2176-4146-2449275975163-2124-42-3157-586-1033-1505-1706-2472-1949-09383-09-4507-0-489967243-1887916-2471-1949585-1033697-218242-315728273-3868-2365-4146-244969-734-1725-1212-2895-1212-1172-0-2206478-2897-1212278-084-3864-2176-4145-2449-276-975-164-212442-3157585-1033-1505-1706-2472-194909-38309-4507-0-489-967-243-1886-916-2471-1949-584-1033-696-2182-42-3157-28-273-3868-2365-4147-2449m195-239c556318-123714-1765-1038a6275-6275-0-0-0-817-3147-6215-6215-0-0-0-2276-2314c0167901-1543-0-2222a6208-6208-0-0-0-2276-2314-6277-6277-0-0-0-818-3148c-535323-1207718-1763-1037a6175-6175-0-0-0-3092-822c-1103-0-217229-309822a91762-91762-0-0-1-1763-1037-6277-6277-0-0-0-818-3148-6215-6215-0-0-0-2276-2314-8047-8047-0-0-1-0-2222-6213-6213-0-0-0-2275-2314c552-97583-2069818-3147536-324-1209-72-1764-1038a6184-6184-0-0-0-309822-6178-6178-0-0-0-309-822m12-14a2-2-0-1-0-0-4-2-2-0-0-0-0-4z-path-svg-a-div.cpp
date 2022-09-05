/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        stack<int> st;
        for(int i = 0; i < n ;i++){
            st.push(i);
        }
        while(st.size() > 1){
            int temp = st.top();
            st.pop();
            int temp2 = st.top();
            st.pop();
            if(knows(temp , temp2))
                st.push(temp2);
            else
                st.push(temp);
        }
        int ans = st.top();
        for(int i = 0; i < n ;i++){
            if(ans == i)
                continue;
            if(knows(ans , i) or !knows(i , ans))
                return -1;
        }
        return st.top();
    }
};