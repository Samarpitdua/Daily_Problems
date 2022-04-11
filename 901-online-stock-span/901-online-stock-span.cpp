class StockSpanner {
public:
    //nearest smaller to left
    stack<pair<int , int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        {
            int ct = 1;
            while(!st.empty() and st.top().first <= price )
            {
                ct += st.top().second , st.pop();
            }
            st.push({price , ct});
            return ct;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */