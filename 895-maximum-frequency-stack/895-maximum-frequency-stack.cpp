#define pi pair<int , pair<int , int>>

class FreqStack {
public:
    //priority_queue<pair<int, pair<int, int>>> pq;
    priority_queue<pi> pq;
    unordered_map<int ,int> mp;
    int time_of_insert = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        pq.push({++mp[val] , {++time_of_insert , val}});
    }
    
    int pop() {
        auto val = pq.top();
        pq.pop();
        int x = val.second.second;
        mp[x]--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */