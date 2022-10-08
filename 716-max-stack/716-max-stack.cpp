// class MaxStack {
// public:
//     stack<int> st1 , st2;
//     MaxStack() {
        
//     }
    
//     void push(int x) {
//         st1.push(x);
//         if(st2.empty() || st2.top() <= x)
//             st2.push(x);
//     }
    
//     int pop() {
//         int val = st1.top();
//         if(!st2.empty() && st2.top() == val)
//             st2.pop();
//         st1.pop();
//         return val;
//     }
    
//     int top() {
//         return st1.top();
//     }
    
//     int peekMax() {
//         return st2.top();
//     }
    
//     int popMax() {
//         int val = st2.top();
//         stack<int> temp;
        
//         while (st2.top() != st1.top()) {
//             temp.push(st1.top());
//             st1.pop();
//         }
        
//         st2.pop();
//         st1.pop();
        
//         while (!temp.empty()) {
//             st1.push(temp.top());
//             if(st2.empty() || st2.top() <= temp.top())
//                 st2.push(temp.top());
//             temp.pop();
//         }
        
//         return val;
//     }
// };

// /**
//  * Your MaxStack object will be instantiated and called as such:
//  * MaxStack* obj = new MaxStack();
//  * obj->push(x);
//  * int param_2 = obj->pop();
//  * int param_3 = obj->top();
//  * int param_4 = obj->peekMax();
//  * int param_5 = obj->popMax();
//  */
class MaxStack {
public:

    int cnt;
    map<int, int, greater<int>> s;
    map<int, stack<int>, greater<int>> ms;
    
    void push(int x) 
    {
        s.insert({cnt, x});
        ms[x].push(cnt);
        cnt++;
    }
    
    int pop() 
    {
        auto x = *s.begin();
        s.erase(s.begin());
        ms[x.second].pop();
        if(ms[x.second].empty())
        {
            ms.erase(x.second);
        }
        return x.second;
    }
    
    int top() 
    {
        return (*s.begin()).second;
    }
    
    int peekMax() 
    {
        return (*ms.begin()).first;
    }
    
    int popMax() 
    {
        auto x = *ms.begin();
        s.erase(x.second.top());
        ms[x.first].pop();
        if(ms[x.first].empty())
        {
            ms.erase(x.first);
        }
        return x.first;
    }
};