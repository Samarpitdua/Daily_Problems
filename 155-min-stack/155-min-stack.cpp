class MinStack {
public:
    //Take 2 stacks st2 will store min elements that will be push into it only on specified conditions
    stack<int>st,st2;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty())
        {
            st.push(val);
            st2.push(val);
        }
        else
        {
            if(st2.top() >= val)
                st2.push(val);
            st.push(val);
        }
    }
    
    void pop() {
        if(st.top() == st2.top())
        {
            st.pop();
            st2.pop();
        }
        else
            st.pop();
    }
    
    int top() {
        if(!st.empty())
            return st.top();
        return -1;
    }
    
    int getMin() {
        return st2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */